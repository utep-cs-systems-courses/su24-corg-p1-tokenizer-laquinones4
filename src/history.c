#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store */
void add_history(List *list, char *str){
  Item *node = malloc(sizeof(Item));

  int len = 0;
  while (str[len] != '\0') {
    len++;
  }

  node->str = malloc((len + 1) * sizeof(char));
  for (int i = 0; i <= len; i++) {
    node->str[i] = str[i];
  }

  node->next = NULL;

  if (list->root == NULL) {
    node->id = 1;
    list->root = node;
  } else {
    Item *temp = list->root;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    node->id = temp->id + 1;
    temp->next = node;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  if (list->root == NULL)
    return "Empty list";
  
  Item *node = list->root;

  while (node->id != id){
    if(node->next == NULL)
      return "No id found";
    node = node->next;
  }
  return node->str;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if (list->root == NULL){
    printf("No history \n");
    return;
  }

  Item *node = list->root;

  while (node != NULL)
    {
      printf(">!%d - %s \n",node->id, node->str);
      node = node->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *node = list->root;

  while (node != NULL){
    Item *nextNode = node->next;
    free(node->str);
    free(node);
    node = nextNode;
  }
  free(list);
}
