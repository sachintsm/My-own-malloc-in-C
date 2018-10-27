#include<stdio.h>
#include<stddef.h>  
#include"mymalloc.h"  //this is the header file that we create before

//initializing the block of memory
void initialized(){
	freeblock->size = max-sizeof(struct block);  //initialized the meta data block is 25000 bytes block
	freeblock->free = 1; //we set flag to  1 to  initialized to block is free. not full
	freeblock->next = NULL; //first meta data block is no next meta data block. So we set it to NULL
}

//make a new block
void split(block *slot, size_t size){
	block *new = (void*)((void*)slot + size + sizeof(block));  //allocate the memory for new block
	new->size = (slot -> size)-size-sizeof(block); //get the new size to the new memory block
	new->free = 1;  // new memory  block, it hase the memory free,  then flag 1(true the condition)
	new->next = slot->next;  //new block is assign to next to the previous block
	slot->size = size; //allocate the new size to the new memory  block size in the heap array
	slot->free = 0;  //then that memory block assign to the, this blosk is now full and flag 0(false)
	slot->next = new; //the new block set to next
}

void *mymalloc(size_t mem_size){
	block *current, *previous;
	void *start;    //this pointer use to return starting address of the memory block

	if(!(freeblock->size)){
		initialized();
		printf("Memory is initialized\n");
	}
	current = freeblock;  //we make the temperary pointer start of the metadata memory block
	while((((current->size < mem_size) || ((current -> free == 0)) && (current->next != NULL)))){
		previous = current;  //set current memory block to preious block
		current = current->next; //currunt -> next set to current mem bock
		printf("This is checked\n");  
	}
	if((current->size) == mem_size){  //check the current memory block size equal  to given mem size
		current->free = 0; //set current mem block full
		start = (void*)(++current);  //set starting address to new new allocated memory block beginning address
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
		start = NULL;  //if there is no memmory to allocate then set starting address to NULL address
		printf("Sorry. No memory to allocate.\n");
	}
}
/*this connect function is using to merge the free memory block after the free some memories**/
void connect(){
	block *current, *previous;
	current = freeblock; 
	while((current->next) != NULL){
		if((current->free) && (current->next->free)){
			current->size = current->size + ((current->next->size) + sizeof(struct block));
			current->next = current->next->next;
		}
		previous = current;
		current = current->next;
	}
}
/*this myfree function use to deallocate the allocated memory*/
void myfree(void *ptr){ //thi smyfree function is ude to allocate the memory to mymalloc. file to enclude the syystem
	if(((void*) Heap <= ptr) && (ptr <= (void*)(Heap + 25000))){
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
int main(){

	printf("Hello world\n");
	return 0;
}

