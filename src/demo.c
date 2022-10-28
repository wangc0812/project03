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
    Matrix* mat1 = createMatrix(row, col, elenum, data);

    // print matrix
    printMatrix(mat1);

    // copy matrix
    Matrix* mat2 = copyMatrix(mat1);
    printMatrix(mat2);  // to confirm the copy function
    
    Matrix* mat3 = addMatrix(mat1, mat2); // matrix add
    printMatrix(mat3);  // to confirm the add function
    Matrix* mat4 = subtractMatrix(mat3, mat2); // matrix sub
    printMatrix(mat4);  // to confirm the sub function


    
    // free memory
    deleteMatrix(mat1);
    deleteMatrix(mat2);
    deleteMatrix(mat3);

    return 0;
}