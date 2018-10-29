#include<stdio.h>
#include<stddef.h>  
#include"mymalloc.h"  //this is the header file that we create before

block *freeblock = (void*)Heap; //cerate a pointer on Heap
/*in here we are starting the first meta data block*/
void initialized(){
	freeblock->size = max-sizeof(block);  //initialized memory block size
	  freeblock->free = 1; //we set flag to 1 to 	initialized to block is free
		freeblock->next = NULL; //first meta data block is no next meta data block. So we set it to NULL
}

/*split function use to  devide the block. if we found 500bytes block. but we want to 200 bytes.
we divide the 500 to 200 and 300 and we use only 200 and other part is set to free*/
void split(block *slot, size_t size){
	block *new = (void*)((void*)slot + size + sizeof(block)); //pointer new is the next meta data mem block address
	  new->size = (slot -> size)-size-sizeof(block); //get the new size to the new memory block (-unnecessay mem size and -befere size blck)
	    new->free = 1; // new memory  block, it hase the memory free,  then flag 1(true the condition)
	      new->next = slot->next; //new block is assign to next to the previous block
	slot->size = size; //allocate the new size to the new memory  block size in the heap array
	  slot->free = 0; //then that memory block assign to the, this blosk is now full and flag 0(false)
	    slot->next = new; //the new block set to next
}
/*this combine function is using to merge the free memory block after the free some memories**/
void combine(){
	block *current, *previous; //this pointers create, to traverse the heap.
	current = freeblock; 
	while((current->next) != NULL){
		if((current->free) && (current->next->free)){
			current->size = current->size + ((current->next->size) + sizeof(struct block));
			 current->next = current->next->next;
		}
		else if((current->free == 1) && (current->next->free == 0)){
			current =current->next; 
		}
		previous = current;
		 current = current->next;
	}
}
/*this my_free function use to deallocate the allocated memory*/
void my_free(void *ptr){ //thi smy_free function is ude to allocate the memory to my_malloc. file to enclude the system
	if(((void*)Heap <= ptr) && (ptr <= (void*)(Heap + 25000))){
		block *current = ptr;
		 current = current - 1;
		  current->free = 1;
		   combine();
	}
	else
	{
		printf("Invalid address..!\n");
	}
}
void *my_malloc(size_t mem_size){
	block *current, *previous;  //this pointers create, to traverse the heap. 
	 void *start_address;    //this pointer use to return starting address allocated memory block

	/*here we check this block before we initialized or not if we initialized before we skip the if condition*/
	if(!(freeblock->size)){
		initialized();
		 printf("Memory is initialized\n");
	}
	current = freeblock;  //we make the temperary pointer start of the metadata memory block
	while((((current->size < mem_size) || ((current -> free == 0)) && (current->next != NULL)))){
		previous = current;  //set current memory block to previous block
		 current = current->next; //currunt -> next set to current mem bock
		  printf("This is checked\n");  
	}
		if((current->size) == mem_size){  //check the current memory block size equal  to given mem size
			current->free = 0; //set current mem block full
			 start_address = (void*)(current++);  //set starting address to new new allocated memory block beginning address
			  printf("Block is now allocated\n"); 
			   return start_address;  
		}
		else if((current->size) > (mem_size + sizeof(block))){
			split(current,mem_size);
			 start_address = (void*)(current++);
			  printf("Block is allocated and splited`\n");
			   return start_address;
		}
		else{
			start_address = NULL;  //if there is no memmory to allocate then set starting address to NULL address
			 printf("Sorry. No memory to allocate.\n");
		
	}
}

