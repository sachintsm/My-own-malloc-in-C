#include<stdio.h>
#include<stddef.h>
# define max 25000

char Heap[max];

/*this below structure to set meata data abuot the dlaata block. in this mete data block store size, free or not 
and next block address*/
typedef struct block
{
	size_t size; //block size
 	 int free;  //block is free or not
	  struct block *next;  //next use to store next meta data block address
}block;

//block *freeblock = (void*)Heap; //there we make a pointer type of block. this freeblock pointer point to the next meta data block

/*this functions define, we use them in mymalloc.c file*/

void initialized(); //initializing the memory block
 void split(block *slot, size_t size); //split the mem blk provide memory and free memory blocks
  void combine();  //merge two memory blocks
   void my_free(void *ptr);  //this function use to free the memory block
    void *my_malloc(size_t mem_size);  // memory allocating fuction 

