#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "define.h"

int main()
{
    printf("test \n");
    const int elenum = 4;
    DATA_TYPE data[4] = {5,2,8,4};
    const INT row = 2;
    const INT col = 2;
    // generate matrix
    Matrix* mat1 =  Matrix_create(row, col, elenum, data);
    // print matrix
    Matrix_print(mat1);
    // copy matrix
    Matrix* mat2 = Matrix_copy(mat1);
    Matrix_print(mat2);  // to confirm the copy function
    
    // free memory
    FREE(mat1);
    FREE(mat2);
    
    return 0;
}