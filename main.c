#include<stdio.h>
#include<stddef.h>
#include"mymalloc.h"

int main(){
 
	int *p  = (int*)my_malloc(100*sizeof(int));
	char *q = (char*)my_malloc(250*sizeof(char));
	int *r  = (int*)my_malloc(1000*sizeof(int));

	my_free(p);

	char *w = (char)my_malloc(700);

	my_free(r);

	int *k  = (int)my_malloc(500*sizeof(int));
	printf("Allocation and deallocation is done successfully!\n");
 	printf("%d\n",&p );
}