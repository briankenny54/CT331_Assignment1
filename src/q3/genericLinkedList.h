#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* print);




//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void* print);

//Delete the element after the given el
void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list, void* data, size_t size, void* print);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, void* print );

listElement* dequeue(listElement* list);

void printChar(void *data);
void printStr(void *data);
void printInt(void *data);
void printFloat(void *data);



#endif
