  #include <stdio.h>

void history(){
  printf("this is your history \n");
}

int main (){
  char stringInput[100];
  char *ptr = stringInput;

 start:
  printf("enter a string: ");
  fgets (stringInput, 100, stdin);

  switch (*ptr){
  case 'q':
    if (*(ptr+1) == '\n')
      goto terminate;
    else
      printf("%s", stringInput);
    break;
  case 'h':
    if (*(ptr+1) == '\n')
      history();
    else
      printf("%s", stringInput);
    break;
  default:
    printf("%s", stringInput);
  }
  
  goto start;
  
 terminate:
  return 0;
}
