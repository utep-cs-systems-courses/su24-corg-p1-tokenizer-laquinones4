#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

void history(){
  printf("this is your history \n");
}

int main (){
  char stringInput[100];
  char **tokens;
  
 start:
  printf("\n");
  printf("'q' to exit | 'h' to see history\n");
  printf("enter a string: ");
  fgets (stringInput, 100, stdin);
  char *ptr = stringInput;

  switch (*ptr){
  case '!':
    printf("this feature will be added later\n");
    break;
    
  case 'q':
    if(*(ptr+1) == '\n')
      goto terminate;
  
  case 'h':
    if(*(ptr+1) == '\n'){
      history();
      break;
    }
    
  default:
    tokens = tokenize(ptr);
    print_tokens(tokens);
  }

  goto start;

 terminate:
  return 0;
}

