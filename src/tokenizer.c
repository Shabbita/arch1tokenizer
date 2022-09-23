#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  char str[100];
  int num;

  /* Interface */
  printf("Hello!\n");

  while(free){  /* Loops until user selects Exit */
    printf("Select a number\n  1. View history\n  2. Enter a sentence\n  3. Tokenize a sentence\n  4. Exit\n  >> ");

    scanf("%d", &num);
    printf("Number: %d\n", num);

    switch(num){
    case 1:
      printf("Case 1\n");
      break;

    case 2:
      printf("Case 2\n");
      break;

    case 3:
      printf("Case 3\n");
      break;

    case 4:
      printf("Exiting...\n");
      exit(0);

    default:
      break;
    }
  }

  
  /* Get a string */
  /* scanf("%[^\n]s", str);
  printf("Your string is: %s\n", str);
  */
  
  return 0;
}
