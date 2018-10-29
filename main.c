#include<stdio.h>
#include<stddef.h>
#include"mymalloc.h"

int main(){
 	printf("Heap starting address is = %d\n",&Heap);
 	printf("\n");

	block *p  = (void*)(block*)my_malloc(1000);
	printf("%d\n",sizeof(*p));
	my_free(p);
	// char *q = (char*)my_malloc(250*sizeof(char));
	// printf("%d\n",sizeof(*q));
	// printf("Pointer p address is = %d\n",&p);
	// printf("Pointer q address is = %d\n",&q);
	printf("\n");
/*
	char *q = (char*)my_malloc(250*sizeof(char));
	printf("%d\n",sizeof(*q));
	printf("Pointer p address is = %d\n",&q);
	printf("\n");

	int *r  = (int*)my_malloc(1000*sizeof(int));
	printf("%d\n",&p );
	printf("Pointer p address is = %d\n",&r);
	printf("\n");

	//my_free(p);

	//char *w = (*char)my_malloc(700);
	printf("%d\n",&p );
	my_free(r);

	//int *k  = (*int)my_malloc(500*sizeof(int));
	printf("Allocation and deallocation is done successfully!\n");
 	printf("%d\n",&p );
 	printf("%d\n",&q );
 	printf("%d\n",&r );*/
 	
}