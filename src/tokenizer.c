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
  int count = count_words(str3);
  char **tokens;

  /* Interface */
  printf("\nWelcome!\n");

  while(free){  /* Loops until user selects Exit */
    printf("\nSelect a number\n  1. View history.\n  2. Enter a sentence.\n  3. Tokenize a sentence.\n  4. Exit\n  >> ");

    scanf("%d", &num);
    printf("Number: %d\n", num);

    switch(num){
    case 1:  //View history and select sentence

      break;

    case 2:  //Enter a sentence
      printf("\nEnter you new sentence:\n  >> ");
      scanf(" %[^\n]s", str);
      printf("Your new sentence is: %s\n", str);
      break;

    case 3:  //Tokenize a sentence
      free(tokens);
      tokens = tokenize(str);
      print_tokens(tokens);
      break;

    case 4:  //Exit
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
    return temp;
  }
  return NULL;
}

char *word_terminator(char *word){
  char *temp = word;

  while(*temp != '\0'){
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
 
  return newStr;
}

char **tokenize(char* str){
  int i=0;
  int j=0;
  int words = 0;
  int len = 0;
  int count = count_words(str);
  char **tokens = malloc((count+1)*sizeof(char *));

  for(i=0; i<=count; i++){
    tokens[i] = (char*)malloc(sizeof(char)*20);
  }

  /* Store string in tokens */
  i=0;
  while(str[i] != '\0'){ 
    if(non_space_char(str[i])){
      tokens[words][j] = str[i];
      j++;
    }
    if(space_char(str[i])){
      words++;
      j=0;
    }
    i++;
    }

  return tokens;
  
}

void print_tokens(char **tokens){
  int i=0;
  printf("Tokens: \n");
  while(*tokens[i] != '\0'){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
  printf("tokens[%d] = %s\n", i, tokens[i]);
}

void free_tokens(char **tokens){
  free(tokens);
}
