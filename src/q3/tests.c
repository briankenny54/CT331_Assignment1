#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"



void runTests(){
  printf("Tests running...\n");

  //...
  
  float a = 10.4;
  
  listElement* l = createEl(&a, 30, &printFloat);
 
  //Test create and traverse
  traverse(l);
  printf("\n");
int d = 45;
  //Test insert after
  listElement* l2 = insertAfter(l, "String test", 30, &printStr);
   traverse(l);
  printf("\n");
  listElement* l3 = insertAfter(l2, &d, 30,&printInt);
  traverse(l);
  printf("\n");



  printf("\nTests complete.\n");
}
