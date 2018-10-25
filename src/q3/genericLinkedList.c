#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
  void* data;
  size_t size;
  struct listElementStruct* next;
  void (*printFn)();
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* print){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->printFn = print;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->printFn(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void* print){
  listElement* newEl = createEl(data, size, print);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}


int length(listElement* list){
	int count = 0;
	listElement* current = list;
  while(current != NULL){
    current = current->next;
	count++;
  }
  printf("%d\n",count);
  return count;
}

void push(listElement** list, void* data, size_t size, void* print){
	  listElement* newEl = createEl(data, size, print);
		newEl->next = *list;
		*list = newEl;
		
}

listElement* pop(listElement** list){
	listElement* temp = *list;
	*list = (*list)->next;
	
	return temp;
	
}

void enqueue(listElement** list, void* data, size_t size, void* print ){
	listElement* newEl = createEl(data, size, print);
	newEl->next = *list;
		*list = newEl;
	
}

listElement* dequeue(listElement* list){
		listElement* newEl;

	listElement* current = list->next;
  while((current->next)->next != NULL){
    current = current->next;
  }
  newEl = current->next;
  current->next = NULL;
  return newEl;
  
}


void printChar(void* data){
	printf("%c\n", *(char*)data);
}

void printStr(void* data){
	printf("%s\n", (char*)data);
}

void printInt(void* data){
	printf("%d\n", *(int*)data);
}

void printFloat(void* data){
	printf("%f\n", *(float*)data);
}
