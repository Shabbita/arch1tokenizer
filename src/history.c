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
  Item *tmp = list->root; 
  Item *newNode = (Item *)malloc(sizeof(Item));

  //If list is empty
  if(tmp->str==NULL){
    tmp->str = str;
    tmp->id = i;
    return;
  } else {
    i++;
    
    while(tmp->next != NULL){
      tmp=tmp->next;
      i++;
    }
  
    tmp->next = newNode;
    newNode->id = i;
    newNode->str = str;
  }
  
}


char *get_history(List *list, int id){
  Item *temp = list->root;
  
  while(temp->id != id){
    temp = temp ->next;
  }
  return temp->str;
}


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


}
