/*Org-Code*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define Hello_World_String "Hello World"

void f(char *p)
{
   p = (char *)malloc(sizeof(char));
   assert(p!=NULL);
   strcpy(p,Hello_World_String);
  }
int main()
{
   char *p;
   f(p);
   printf("%s\n",p);
   free(p);
   return 0;
  }
Output:- Segmentation Fault

/*Mod-Code*/
Approach-1:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define Hello_World_String "Hello World"

void f(char **p)
{
   *p = (char *)malloc(sizeof(char));
   assert(*p!=NULL);
   strcpy(*p,Hello_World_String);
  }
int main()
{
   char *p = NULL;
   f(&p);
   printf("%s\n",p);
   free(p);
   return 0;
   }
   
 Approach-2:
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define Hello_World_String "Hello World"

void f(char *p)
{
   //p = (char *)malloc(sizeof(char));
   assert(p!=NULL);
   strcpy(p,Hello_World_String);
  }
int main()
{
   char *p;
   p = (char *)malloc(sizeof(char));  
   f(p);
   printf("%s\n",p);
   free(p);
   return 0;
   }
 
