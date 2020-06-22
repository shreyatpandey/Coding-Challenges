/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = AColSize[0];
    *returnColumnSizes = (int*)malloc(sizeof(int)*AColSize[0]);
    int i;
    for(i =0;i<AColSize[0];i++){
        (*returnColumnSizes)[i] = ASize;
    }
    
    int** TransposeMatrix = (int**)malloc(sizeof(int*)*(AColSize[0]));
    for(i =0;i<AColSize[0];i++){
        TransposeMatrix[i] = (int*)malloc(sizeof(int)*ASize);
    }
    int j;
    for( i =0;i<ASize;i++){
        for(j = 0;j<AColSize[0];j++){
            TransposeMatrix[j][i] = A[i][j];
        }
    }
    return TransposeMatrix;

}

