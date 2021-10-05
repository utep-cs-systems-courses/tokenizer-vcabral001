#ifndef _HISTORY_

#define _HISTORY_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string.h"


typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;



/* Initialize the linked list to keep the history. */

List* init_history(){
  List* list = (List*) malloc(sizeof(List));
  return list;
 
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str)
{

  int id = 1;

  //creating new node and a temp head node

  Item* new_node = (Item*) malloc(sizeof(Item));



  //new_node->str = (char*)malloc(sizeof(struct s_Item*));

  new_node->str = str;



  Item* temp = list->root;



  //if list is empty

  if (!list->root){

    new_node->id = 0;

    list->root = new_node;

    return;

  }

  //go to last node

  while (temp->next){

    temp = temp->next;

    id++;

  }

  new_node->id = id;

  temp->next = new_node;

  new_node->next = NULL;

  return;

}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item* iterator = list->root;

  while(iterator)

  {

    if (iterator->id == id)

      {

	return iterator->str;

      }

    iterator = iterator->next;

  }

return 0;
}





/*Print the entire contents of the list. */

void print_history(List *list)
{

  Item* iterator = list->root;

  while(iterator)

    {

      printf("%d: ", iterator->id);

      printf("%s", iterator->str);

      iterator = iterator->next;

    }

}


/*Free the history list and the strings it references. */

void free_history(List *list)
{

  Item* iterator = list->root;

  Item* temp;

  while(iterator)

    {

      temp = iterator;

      iterator = iterator->next;

      free(temp->str);

      free(temp);

    }

  // free(list);

}


#endif
