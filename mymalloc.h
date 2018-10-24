#include<stdio.h>
#include<stdbool.h>
#include<stddef.h>

char heap[25000];

typedef struct block
{
	size_t size;       //Carries the size of the block described by it
	int free;       //this is use to know weahter the selected metadata block is free or not
	struct block *next;  //point to next meta data
}block;

struct block *freeblock = (void*)heap;

/*this functions define, we use them in mymalloc.c file*/

void initialized();
void split(struct block *slot, size_t size);
void mymalloc(size_t mem_size);  
void connect();  //merge two memory blocks
void freeblock(void *ptr);  //this function use to free the memory block