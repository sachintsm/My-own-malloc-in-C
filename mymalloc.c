#include<stdio.h>
#include<stdbool.h>
#include<stddef.h>
#include"mymalloc.h"  //this is the header file that we create before


//initializing the block of memory
void initialized(){
	freeblock->size = 25000-sizeof(struct block);  //initialized the meta data block is 25000 bytes block
	freeblock->free = 1; //we set flag to  1 to  initialized to block is free. not full
	freeblock->next = NULL; //first meta data block is no next meata data block. So we set it to NULL
}

//make a new block
void split(struct splitblock *slot, size_t size){
	struct block *new = (void*)((void*)splitblock + size + sizeof(struct block));  //allocate the memory for new block
	new->size = (splitblock)-size-sizeof(struct block); //get the new size to the new memory block
	new->free = 1;  // new memory  block, it hase the memory free,  then flag 1(true the condition)
	new->next = splitblock->next;  //new block is assign to next to the previous block
	splitblock->size = size; //allocate the new size to the new memory  block size in the heap array
	splitblock->free = 0;  //then that memory block assign to the, this blosk is now full and flag 0(false)
	splitblock->next = new; //the new block set to next
}

void *mymalloc(size_t mem_size){
	struct block *current, *previous;
	void *start;    //this pointer use to return starting address of the memory block

	if(!(freeblock->size)){
		initialized();
		printf("Memory is initialized\n");
	}
	current = freeblock;  //we make the temperary pointer statr of the metadata memory block
	while((((current->size < mem_size) || ((current -> free == 0)) && (current->next != NULL)))){
		previous = current;
		current = current->next;
		printf("This is checked\n");
	}
	if((current->size) == mem_size){
		current->free = 0;
		start = (void*)(++current);
		printf("Block is now allocated\n");
		return start;
	}
	else if((current->size) > (mem_size + sizeof(struct block))){
		split(current,mem_size);
		start = (void*)(++current);
		printf("Fitting block allocated with a split\n");
		return start;
	}
	else{
		start = NULL;
		printf("Sorry. No memory to allocate.\n");
	}
}
/*this connect function is using to merge the free memory block aftr=er the free some memories**/
void connect(){
	struct block *current, *previous;
	current = freeblock;
	while((current -> next) != NULL){
		if((current -> free) && (current->next-> free)){
			current -> size = current->size + ((current->next->size) + sizeof(struct block));
			current->next = current -> next -> next;
		}
		previous = current;
		current = current->next;
	}
}
/*this myfree function use to deallocate the allocated memory*/
void myfree(void *ptr){
	if(((void*) heap <= ptr) && (ptr <= (void*)(heap + 25000))){
		struct block * current = ptr;
		--current;
		current->free = 1;
		connect();
	}
	else
	{
		printf("Please provide a valid pointer allocated by MyMalloc\n");
	}
}
