#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vector
{
  void **create_space;
  int vector_size ;
  int no_of_elements ;
}vector;

void vector_initialize(vector* v)
{
	v->create_space = NULL;
	v->vector_size = 0;
	v->no_of_elements = 0;

}

int no_of_elements(vector* v)
{
  return (v->no_of_elements);

}
void vector_append(vector* v,void* insert)
{
 //check vector is empty or not
 if(v->vector_size == 0)
 {
    v->vector_size = 100; //allocate some size to vector
    v->create_space = malloc(sizeof(v->vector_size));
    memset(v->create_space,'\0',sizeof(v->vector_size));
 }
//if size is full, resize the vector
if(v->no_of_elements == v->vector_size)
{
  v->vector_size *= 2;
  v->create_space = realloc(v->create_space, sizeof(v->vector_size));
  
 }
 v->create_space[v->no_of_elements] = insert;
 v->no_of_elements+=1;
}

void *vector_get(vector* v,int index) //get the value at particular index
{
  //check index is not greater than no_of_elements
  if(index >= v->no_of_elements)
   	return NULL;
   
 return  v->create_space[index];
}
void vector_delete (vector* v,int index)
{
  if(index >= v->no_of_elements)
	return;

  for(int i=index+1,j=index;i<v->no_of_elements;++i)
	{
   		v->create_space [j] = v->create_space[i];
		j++;
	}
      	 
	v->no_of_elements-=1;
}
void delete_space(vector* v)
{
  free(v->create_space);
}


int main()
{

  vector v;
  vector_initialize(&v);
  
  vector_append(&v,"5");
  vector_append(&v,"10");
  vector_append(&v,"15");

  for(int i=0;i<no_of_elements(&v);i++)
  {
    printf("%s\n", (char*)vector_get(&v,i));
  }
 vector_delete(&v,1);
 printf("After deleting the second element\n");
 
  for(int i=0;i<no_of_elements(&v);i++)
  {
     printf("%s\n",(char*)vector_get(&v,i));
   }
  delete_space(&v);

 return 0;
}

  
   

