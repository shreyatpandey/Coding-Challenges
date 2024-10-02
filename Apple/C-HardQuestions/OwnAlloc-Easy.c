#include<stdio.h>
#include<stdlib.h>

#define MAX_CAPACITY 20000
char memory[MAX_CAPACITY] = {0};

struct block
{
 size_t size;
 int free;
 struct block *next; 
};

struct block *freeList=(void*)memory;

void initialize();
void split(struct block *fitting_slot,size_t size);
void *MyMalloc(size_t noOfBytes);
void merge();
void MyFree(void* ptr);

void initialize()
{
  freeList->size=MAX_CAPACITY-sizeof(struct block);
  freeList->free=1;
  freeList->next=NULL;
}

void split(struct block *fitting_slot,size_t size)
{
    struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block));
    new->size=(fitting_slot->size)-size-sizeof(struct block);
    new->free=1;
    new->next=fitting_slot->next;
    fitting_slot->size=size;
    fitting_slot->free=0;
    fitting_slot->next=new;
}


void *MyMalloc(size_t noOfBytes)
{
 printf("noOfBytes:%zu\n", noOfBytes);
 struct block *curr,*prev;
 void *result;
 printf("freeList->size:%zu\n", freeList->size);
 if(!(freeList->size))
 {
  initialize();
  printf("Memory initialized\n");
 }
 curr=freeList;
 printf("curr->size:%zu\n", curr->size);
 while((((curr->size)<noOfBytes)||((curr->free)==0))&&(curr->next!=NULL))
 {
  prev=curr;
  curr=curr->next;
  printf("One block checked\n");
 }
 if((curr->size)==noOfBytes)
 {
  curr->free=0;
  result=(void*)(++curr);
  printf("Exact fitting block allocated\n");
  return result;
 }
 else if((curr->size)>(noOfBytes+sizeof(struct block)))
 {
  split(curr,noOfBytes);
  result=(void*)(++curr);
  printf("Fitting block allocated with a split\n");
  return result;
 }
 else
 {
  result=NULL;
  printf("Sorry. No sufficient memory to allocate\n");
  return result;
 }
}

void merge()
{
  struct block *curr,*prev;
  curr=freeList;
  while((curr->next)!=NULL)
  {
    if((curr->free) && (curr->next->free))
    {
        curr->size+=(curr->next->size)+sizeof(struct block);
        curr->next=curr->next->next;
    }
  prev=curr;
  curr=curr->next;
  }
}

void MyFree(void* ptr)
{
  if(((void*)memory<=ptr)&&(ptr<=(void*)(memory+20000)))
  {
    struct block* curr=ptr;
    --curr;
    curr->free=1;
    merge();
   }
   else 
    printf("Please provide a valid pointer allocated by MyMalloc\n");
}



int main()
{
 printf("--- sizeofblock ---:%ld\n", sizeof(struct block));
 printf("=== Test Case-1 ===\n");
 int *p=(int*)MyMalloc(100*sizeof(int));
 printf("=== Test Case-2 ===\n");
 char *q=(char*)MyMalloc(250*sizeof(char));
 printf("=== Test Case-3 ===\n");
 int *r=(int*)MyMalloc(1000*sizeof(int));
 MyFree(p);
 char *w=(char*)MyMalloc(700);
 char *w=(char*)MyMalloc(700);
 MyFree(r);
 int *k=(int*)MyMalloc(500*sizeof(int));
 int *k=(int*)MyMalloc(500*sizeof(int));
 printf("Allocation and deallocation is done successfully!");
 return 0;
}
/*
--- sizeofblock ---:24
=== Test Case-1 ===
noOfBytes:400
freeList->size:0
Memory initialized
curr->size:19976
Fitting block allocated with a split
=== Test Case-2 ===
noOfBytes:250
freeList->size:400
curr->size:400
One block checked
Fitting block allocated with a split
=== Test Case-3 ===
noOfBytes:4000
freeList->size:400
curr->size:400
One block checked
One block checked
Fitting block allocated with a split
noOfBytes:700
freeList->size:400
curr->size:400
One block checked
One block checked
One block checked
Fitting block allocated with a split
noOfBytes:2000
freeList->size:400
curr->size:400
One block checked
One block checked
Fitting block allocated with a split
*/