#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "history.h"
#include "tokenizer.h"

void print_wanted_token(char* str, List *list){
  int strSize = token_terminator(str) - token_start(str);
  int valid = 1;
  char *tempStr = malloc(strSize - 1);
  
  int i;
  for (i = 1; i < strSize; i++) {
    if (!isdigit(str[i])) {
      valid = 0;
      break;
    }
    tempStr[i-1] = str[i];
  }
  
  if (valid == 0){
    printf("%sinvalid input\n", str);
    return;
  }
  else{
    int historyId;
    sscanf(tempStr, "%d", &historyId);
    char *historyStr = get_history(list, historyId);
    char **token = tokenize(historyStr);
    print_tokens(token);
    free_tokens(token);
  }
}

int main (){
  List *list = init_history();
  char stringInput[100];
  char **tokens;

 start:
  printf("\n");
  printf("'q' to exit | 'h' to see history\n");
  printf("enter a string: ");
  fgets (stringInput, 100, stdin);

  char *str = stringInput;
  switch (*str){
  case '\n':
    goto start;

  case ' ':
    goto start;
    
  case '!':
    if (isdigit(*(str+1))){
      print_wanted_token(str, list);
      break;
    } else{
      printf("%sinvalid input\n", str);
      goto start;
    }

  case 'q':
    if(*(str+1) == '\n')
      goto terminate;

  case 'h':
    if(*(str+1) == '\n'){
      print_history(list);
      break;
    }

  default:
    tokens = tokenize(str);
    print_tokens(tokens);
    add_history(list, str);
  }
  goto start;
  
 terminate:
  return 0;
}
