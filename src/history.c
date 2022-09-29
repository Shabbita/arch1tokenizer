#include <stdio.h>
#include <stdlib.h>
#include "history.h"
//#include "tokenizer.c"

List* init_history(){
  List *list = malloc(sizeof(List));
  list-> root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str){
  int i=1;
  Item *tmp = list->root; 
  Item *newNode = (Item *)malloc(sizeof(Item));

  //If list is empty
  if(tmp->str==NULL){
    tmp->str = str;
    tmp->id = i;
    return;
  } else {
    i++;
    //If not empty
    printf("Root's string: %s\n", tmp->str);

    while(tmp->next != NULL){
      tmp=tmp->next;
      i++;
    }
  
    tmp->next = newNode;
    newNode->id = i;
    newNode->str = str;
  }
  /*
  //newNode->str = str;
  //newNode->next = NULL;

  
  //If list is empty, save in the root
  if(list->root->str==NULL){
    printf("1er nodo\n");
    list->root->str = str;
    list->root->id = i;
    return;
  }

  tmp = list->root;
  i++;
  
  //Add to the end of the list
  while(tmp->next != NULL){
    i++;
    printf("\nTRAVERSING\n");
    tmp = tmp->next;
  }

  tmp->next = newNode;
  tmp->next->id = i;
  tmp->next->str = str;
  */
  
}


/*char *get_history(List *list, int id){}*/


void print_history(List *list){
  Item *tmp = list->root;

  if(list->root->str==NULL){
    printf("Your history list is empty.\n");
    return;
  }

  while(tmp != NULL){
    printf("%d. %s\n", tmp->id, tmp->str);
    tmp = tmp->next;
  }

  printf("\n");

}
