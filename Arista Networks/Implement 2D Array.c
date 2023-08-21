int** my2DAiloc(int rows, int cols) 
{ 
  int i;
 int header = rows * sizeof(int*);
 int data = rows * cols * sizeof(lnt);
 int** rowptr = (int**)malloc(header + data);
 if (rowptr == NULL) return NULL; 
 int* buf = (int*) (rowptr + rows);
 for (i = 0; i < rows; i++)
 {
    rowptr[i] = buf + i*cols;
  }
  return rowptr;
}
