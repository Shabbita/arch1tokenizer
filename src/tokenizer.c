#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char str[100];                      //Empty char to save string
  char *strTemp = NULL;               //Empty char pointer to save new sentences
  char *strSelected = NULL;           //Save selected sentence from the history
  int len;                            //Get the length of a string  
  int num;                            //Save number selected in the interface
  int numStr;                         //Save number for the id of the sentence
  int lenList = 0;
  char **tokens;                      //Saves the pointer address of the **tokens
  List *history = init_history();     //Initialize the linked list for the history

  /* Interface */
  printf("\nWelcome!\n");

  while(free){                        //Loops until user selects Exit
    printf("\nSelect a number:\n  1. View history and select a sentence.\n  2. Enter a sentence.\n  3. Tokenize a sentence.\n  4. Exit\n  >> ");
    scanf("%d", &num);                //Gets number from the "interface" --> switch cases
    printf("\n");
    
    switch(num){
    case 1:                           //View history and select sentence
      printf("1) History:\n");

      //Prints all the history list, or "Your history is empty" if linked list is empty
      print_history(history);

      if(history->root->str != NULL){ //Prints and ask user to select sentence
	//Asks user to select a sentence to get the tokens
	printf("\nSelect a sentence to get tokens.\n  >> ");
	scanf("%d", &numStr);
	printf("NUMBER SELECTED: %d of %d\n", numStr, lenList);
	if(numStr <= lenList){
	  strSelected = get_history(history, numStr);  //Save the pointer address to the sentence
	  printf("\nSelected sentence: %s\n", strSelected);
	  printf("\n");
	} else {
	  printf("Number not available on the list. Try again.\n");
	}
      }


      break;

    case 2:                           //Enter a sentence	    
      printf("2) Enter a new sentence.\nEnter you new sentence:\n  >> ");
      scanf(" %[^\n]s", str);
      printf("\nYour new sentence is: %s\n", str);

      for(len=0; str[len] != '\0'; len++);  //Get the length of the new sentence

      // Create a new allocate string for new sentence
      strTemp = copy_str(str, len);

      //Add the new sentence to the history (linked list)
      add_history(history, strTemp);

      lenList++;                      //Gets the length of the linked list;

      
      break;

    case 3:                           //Tokenize a sentence
      printf("3) Tokenize a sentence\n");

      if(strSelected != NULL){
	printf("Sentence selected: %s\n", strSelected);
	tokens = tokenize(strSelected);  //Tokenize the selected sentence
	print_tokens(tokens);
      } else {                        //If strSelected does not directs to a sentence
	printf("No sentence selected.\n");
      }
      break;

    case 4:                           //Exit
      printf("\n4) Exit the program\nGood bye!\n");
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

/* Prints all the tokens from the selected sentence*/
void print_tokens(char **tokens){     //Prints the char in **tokens
  int i=0;
  printf("Tokens: \n");
  while(*tokens[i] != '\0'){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
  printf("tokens[%d] = %s\n", i, tokens[i]);
}

/* Free memory of the tokens saved */
void free_tokens(char **tokens){      //Removes all from **tokens
  free(tokens);
}

