#include<stdio.h>
#include<stdlib.h>

typedef struct Interval
{
   int start;
   int end;
	
}interval;

void sort_array( interval arr[],int n)
{
    int i;
    int temp;
    temp=0;
    int temp1=0;
    int temp2=0;
    for(i=0;i<n;i++)
    {
        if(arr[i].start>arr[i].end)
        {
           temp = arr[i].start;
           arr[i].start = arr[i].end;
           arr[i].end = temp;
        }
    }
    for(i=0;i<n;i++)
    {
    	if(arr[i].start>arr[i+1].start)
    	{
    		temp1= arr[i+1].start;
    		arr[i+1].start = arr[i].start;
    		arr[i].start = temp1;
            
            temp2=arr[i+1].end;
            arr[i+1].end = arr[i].end;
            arr[i].end = temp2;
    	}
    }
    printf("The sorted array list is\n");
    printf("{");
  
    for(i=0;i<n;i++)
    {
    	printf("(");
    	printf("%d,%d",arr[i].start,arr[i].end);
    	printf(")");

    
    }
    printf("}\n");
    
}


struct Interval* merge(interval array[],int intervalsize,int* returnsize)
{
    sort_array(array,intervalsize);
    struct Interval *returnarray=NULL;
    returnarray = malloc(sizeof(struct Interval));

int m=0;
int i;
for(i=0;i<intervalsize;i++)
{
	
    if(array[m].end>=array[m+1].start)
    {
        
        if(array[m].end<array[m+1].end)
        {
            array[m].end = array[m+1].end;
           }
      
     }
     else
     	m++;
      array[m+1]= array[i+1];
 }
returnsize = &m;  
      
int j;
printf("The merged list array is\n");
printf("{");
for(j=0;j<=m;j++)
{
	returnarray[j] = array[j];
	printf("(");
	printf("%d %d",returnarray[j].start,returnarray[j].end);
	printf(")");
	
}
printf("}\n");


return(returnarray);

}




 


