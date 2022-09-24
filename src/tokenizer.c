#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  char str[100];
  char *str2 = "Hello World!";
  char *str3 = "hola mundo hello worlds";
  char *temp;
  
  int num;
  char c = ' ';
  char c2 = 'a';
  char c3 = '\t';
  

  /* Interface */
  printf("Hello!\n");

  while(free){  /* Loops until user selects Exit */
    printf("\nSelect a number\n  1. View history\n  2. Enter a sentence\n  3. Tokenize a sentence\n  4. Exit\n  >> ");

    scanf("%d", &num);
    printf("Number: %d\n", num);

    switch(num){
    case 1:
      tokenize(str3);
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
  /* Prints a string */
  /*printf("Your string is: %s\n", str);
  */
  
  return 0;
}

int space_char(char c){
  if (c== '\t' || c==' ')
    return 1;
  return 0;
}

int non_space_char(char c){
  if (c=='\t' || c==' ')
    return 0;
  return 1;
}

char *word_start(char *strPtr){
  char *temp = strPtr;

  if(*temp != '\0'){
    while(*temp == ' '){
      temp++;
    }
    /*printf("\nFirst char is: %c\n", *temp);*/
    return temp;
  }
  return NULL;
}

char *word_terminator(char *word){
  char *temp = word;

  while(*temp != '\0'){
    /*printf("%c\n", *temp);
      printf("%p\n", temp);*/
    temp++;
  }
  return temp;
}

int count_words(char *str){
  int count = 0;
  char *temp = str;

  while(*temp != '\0'){
    if(*temp == ' '){
      count++;
    }
    temp++;
  }
  count++;
  return count;
}

char *copy_str(char *inStr, short len){
  char *newStr;
  int i;
  newStr = (char*)malloc(len);

  while(i <= len){
    newStr[i] = inStr[i];
    i++;
  }
  /*
  while(*newStr != '\0'){
    printf("newStr: %c, %p\n", *newStr, newStr);
    printf("inSrt: %c, %p\n", *inStr, inStr);
    newStr++;
    inStr++;
  }
  */
 
  return newStr;
}

char **tokenize(char* str){
  int i;
  int count = count_words(str);

  char **tokens = malloc(count*sizeof(*str));
  for(i=0; i<count; i++){
    tokens[i] = malloc(20*sizeof(**tokens));
  }

  
  


  return tokens;
}
