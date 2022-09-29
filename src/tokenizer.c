#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char str[100];                      //Empty char to save string
  char *str2 = "Hello World!";  //TEST
  char *str3 = "hola mundo hello worlds";  //TEST
  char *strTemp;                      //Empty char pointer to save new sentences
  int len;                            //Get the length of a string
  
  int num;                            //Save number selected in the interface
  int count = count_words(str3);
  char **tokens;
  List *history = init_history();

  /* Interface */
  printf("\nWelcome!\n");

  while(free){                        //Loops until user selects Exit
    printf("\nSelect a number\n  1. View history and select a sentence.\n  2. Enter a sentence.\n  3. Tokenize a sentence.\n  4. Exit\n  >> ");
    scanf("%d", &num);                //Gets number from the "interface" --> switch cases
    printf("Number: %d\n", num);      //Recalls selected number to the user

    switch(num){
    case 1:                           //View history and select sentence

      //First prints all the history, or "Your history is empty" if linked list is empty
      print_history(history);

      //DONT PRINT IF THE HISTORY IS EMPTY
      //Asks user to select a sentence to get the tokens
      printf("Select a sentence to get tokens.\n  >> ");
      
      
      break;

    case 2:                           //Enter a sentence
      printf("\nEnter you new sentence:\n  >> ");
      scanf(" %[^\n]s", str);
      printf("Your new sentence is: %s\n", str);

      for(len=0; str[len] != '\0'; len++);  //Get the length of the new sentence

      // Create a new allocate string for new sentence
      strTemp = copy_str(str, len);

      //Add the new sentence to the history (linked list)
      add_history(history, strTemp);
      break;

    case 3:                           //Tokenize a sentence
      //len = len_word(str2);
      free(tokens);
      tokens = tokenize(str);
      print_tokens(tokens);
      break;

    case 4:                           //Exit
      printf("Exiting...\n");
      exit(0);

    default:                          //Default in case incorrect number
      printf("Option not available. Please try again.\n");
      break;
    }
  }
  return 0;
}

/**************************** Functions ****************************/

int space_char(char c){               //Returns 1 if character is a space or \t
  if (c== '\t' || c==' ')
    return 1;
  return 0;
}

int non_space_char(char c){           //Returns 1 if character is not a space or \t
  if (c=='\t' || c==' ')
    return 0;
  return 1;
}

char *word_start(char *strPtr){       //Returs the pointer to the start of the string
  char *temp = strPtr;

  if(*temp != '\0'){
    while(*temp == ' '){
      temp++;
    }
    return temp;
  }
  return NULL;
}

char *word_terminator(char *word){    //Returns the pointer to the end of the wordd
  char *temp = word;

  while(*temp != '\0'){
    temp++;
  }
  return temp;
}

int count_words(char *str){           //Returns the number of words in the string
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

char *copy_str(char *inStr, short len){  //Returns a new pointer with a copy of the str
  char *newStr;
  int i;
  newStr = (char*)malloc(len);

  while(i <= len){
    newStr[i] = inStr[i];
    i++;
  }
 
  return newStr;
}

char **tokenize(char* str){           //Returns a pointer to pointer of the str made to tokens
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
/*
int len_word(char *str){              //Gets the length of the string
  int len = 0;
  char *start = word_start(str);
  char *end = word_terminator(str);
  len = end - start;
  printf("Lenght of the word %s is %d: ",str,len);
  return len;
}
*/

void print_tokens(char **tokens){     //Prints the char in **tokens
  int i=0;
  printf("Tokens: \n");
  while(*tokens[i] != '\0'){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
  printf("tokens[%d] = %s\n", i, tokens[i]);
}

void free_tokens(char **tokens){      //Removes all from **tokens
  free(tokens);
}

