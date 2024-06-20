#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return (c == '\t' || c == ' ');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  return (c != '\t' && c != ' ' && c != '\0' && c != '\n');
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  while (*str){
    if (non_space_char(*str)) return str;
    str++;
  }
  return NULL;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while (non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  str = token_start(str);

  while (str != NULL && *str != '\0'){
    str = token_terminator(str);
    count++;
    str = token_start(str);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *copyStr = malloc((len + 1) * sizeof(char));
  for (int i = 0; i < len; i++){
    copyStr[i] = inStr[i];
  }
  copyStr[len] = '\0';
  return copyStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str){
  int tokens = count_tokens(str);
  char **tokenize = malloc((tokens + 1) * sizeof(char *));
  char *token = token_start(str);

  int i;
  for(i = 0; i < tokens; i++){
    int len = token_terminator(token) - token;
    tokenize[i] = copy_str(token, len);
    token = token_terminator(token);
    token = token_start(token);
  }
  tokenize[i] = '\0';

  return tokenize;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 1;

  while (*tokens != NULL && **tokens != '\0'){
    printf("token %d: %s \n", i++, *tokens);
    tokens++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  char **token = tokens;

  while (*token != NULL){
    free(*token);
    token++;
  }
  free(tokens);
}
