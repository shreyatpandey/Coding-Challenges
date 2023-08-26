/* Easier Approach */
int** my2DAllocEasy(int rows, int cols)
{
  int **rowptr;
  rowptr = (int**)malloc(sizeof(int*));
  for(int i=0;i<rows;i++)
  {
      rowptr[i] = (int*)malloc(sizeof(int)*cols); 
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
