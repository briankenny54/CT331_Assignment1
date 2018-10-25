#include <stdio.h>

int main(int arg, char* argc[]){
 	int a;
	int *b;
	long c;
	double *d;
	char **e;
	
  printf("%d %d %d %d %d ", sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e));
  return 0;
}
