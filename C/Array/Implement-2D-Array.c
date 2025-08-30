#include <stdio.h>
#include <stdlib.h>

/* Easier Approach */
int** my2DAllocEasy(int rows, int cols)
{
  int **rowptr;
  rowptr = (int**)malloc(rows * sizeof(int*));
  if (rowptr == NULL) return NULL;  // Check for allocation failure
  
  for(int i = 0; i < rows; i++)
  {
      rowptr[i] = (int*)malloc(cols * sizeof(int));
      if (rowptr[i] == NULL) {
          // Clean up previously allocated memory if allocation fails
          for(int j = 0; j < i; j++) {
              free(rowptr[j]);
          }
          free(rowptr);
          return NULL;
      }
  }
  return rowptr;
}

/* Tricky */
int** my2DAiloc(int rows, int cols) 
{ 
  int i;
 int header = rows * sizeof(int*);
 int data = rows * cols * sizeof(int);
 int** rowptr = (int**)malloc(header + data);
 if (rowptr == NULL) return NULL; 
 int* buf = (int*) (rowptr + rows);
 for (i = 0; i < rows; i++)
 {
    rowptr[i] = buf + i*cols;
  }
  return rowptr;
}
