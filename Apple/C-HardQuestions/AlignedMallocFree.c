#include<stdio.h>
#include<stdlib.h>

void *aligned_malloc(size_t bytes, size_t alignment)
{
void *p1 ,*p2; // basic pointer needed for computation.

/* 1.We need to use malloc provided by C. First we need to allocate memory
of size bytes + alignment + sizeof(size_t) . 
2.We need 'bytes' because user requested it. 
3. We need to add 'alignment' because malloc can give us any address and we need to find multiple of 'alignment', so at maximum multiple
of alignment will be 'alignment' bytes away from any location. 
4. We need 'sizeof(size_t)' for implementing 'aligned_free', since we are returning modified memory pointer, not given by malloc ,to the user, 
we must free the memory allocated by malloc not anything else. 
5. So I am storing address given by malloc just abovepointer returning to user. Thats why I need extra space to store that address.
Then I am checking for error returned by malloc, if it returns NULL then
aligned_malloc will fail and return NULL.
*/
if((p1 =(void *) malloc(bytes + alignment + sizeof(size_t)))==NULL)
return NULL;

/* Next step is to find aligned memory address multiples of alignment.
By using basic formule I am finding next address after p1 which is
multiple of alignment.I am storing new address in p2.
*/
size_t addr=(size_t)p1+alignment+sizeof(size_t);

p2=(void *)(addr - (addr%alignment));

/* Final step, I am storing the address returned by malloc 'p1' just "size_t"
bytes above p2, which will be useful while calling aligned_free.
*/
*((size_t *)p2-1)=(size_t)p1;

return p2;
}

/************************************************
Name :- aligned_free
Arguments :- pointer to be freed
Returns :- Nothing

*************************************************/

void aligned_free(void *p )
{
/* Find the address stored by aligned_malloc ,"size_t" bytes above the
current pointer then free it using normal free routine provided by C.
*/
free((void *)(*((size_t *) p-1)));
}
