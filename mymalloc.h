#include<stdio.h>
#include<stddef.h>
# define max 25000

char Heap[max];

typedef struct block
{
	size_t size;       //Carries the size of the block described by it
	int free;       //this is use to know weahter the selected metadata block is free or not
	struct block *next;  //point to next meta data
}block;

struct block *freeblock = (void*)Heap;

/*this functions define, we use them in mymalloc.c file*/

void initialized();
void split(block *slot, size_t size);
void *mymalloc(size_t mem_size);  // memory allocating  fuction 
void connect();  //merge two memory blocks
void myfree(void *ptr);  //this function use to free the memory block


