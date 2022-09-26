#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list-> root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str){
  int i=1;

  Item *newNode = (Item *)malloc(sizeof(Item));
  newNode->str = str;
  newNode->next = NULL;
  Item *tmp = list->root;

  printf("list first: %s\n", list->root->str);
  
  //If list is empty
  if(tmp==NULL){
    list->root = newNode;
    list->root->id = i;
    return;
  }
 
  //Add to the end of the list
  while(tmp->next != NULL){
    printf("ADDING..%d. %s\n", tmp->id, tmp->str);
    i++;
    tmp = tmp->next;
  }

  tmp->next = newNode;
  tmp->id = i;
  
}


/*char *get_history(List *list, int id){}*/


void print_history(List *list){
  Item *tmp = list->root;

  Item *newNode = (Item *)malloc(sizeof(Item));
  newNode->id = 1;
  newNode->str = "Hola 1";

  Item *newNode2 = (Item *)malloc(sizeof(Item));
  newNode2->id = 2;
  newNode2->str = "Hola 2";

  newNode->next = newNode2;
  newNode2->next = NULL;

  list->root = newNode;
  

  if(list->root->str==NULL){
    printf("Your history list is empty.\n");
    return;
  }

  tmp=list->root;

  while(tmp != NULL){
    printf("%d. %s\n", tmp->id, tmp->str);
    tmp = tmp->next;
  }

}
