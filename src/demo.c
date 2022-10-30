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
    printf("create a Matrix \n");
    Matrix* mat1 = createMatrix(row, col, elenum, data);

    // print matrix
    printMatrix(mat1);

    // copy matrix
    printf("copy a Matrix \n");
    Matrix* mat2 = copyMatrix(mat1);
    printMatrix(mat2);  // to confirm the copy function
    
    printf("add two Matrices \n");
    Matrix* mat3 = addMatrix(mat1, mat2); // matrix add
    printMatrix(mat3);  // to confirm the add function
    printf("subtrucy two Matrices \n");
    Matrix* mat4 = subtractMatrix(mat3, mat2); // matrix sub
    printMatrix(mat4);  // to confirm the sub function

    // matrix add scalar
    printf("matrix add scalar(6.6) \n");
    DATA_TYPE b = 6.6;
    Matrix* mat5 = addScalar(mat1, b);
    printMatrix(mat5);  // to confirm the add scalar function

    printf("matrix subtract scalar(6.6) \n");
    Matrix* mat6 = subScalar(mat1, b);
    printMatrix(mat6);  // to confirm the add scalar function

    printf("matrix mutiple scalar(2.0) \n");
    DATA_TYPE c = 2.0;
    Matrix* mat7 = multiplyScalar(mat1, c);
    printMatrix(mat7);  // to confirm the add scalar function

    printf("find the minimal and maximal values of a matrix \n");
    DATA_TYPE  max = maxelem(mat1);
    DATA_TYPE  min = minelem(mat1);
    printf("max value = %f, min value = %f\n", max , min );

    printf("multiply two matrices. \n");
    Matrix* C = mulMatrix(mat1, mat2);
    printMatrix(C);


    // free memory
    deleteMatrix(mat1);
    deleteMatrix(mat2);
    deleteMatrix(mat3);
    deleteMatrix(mat4);
    deleteMatrix(mat5);
    deleteMatrix(mat6);
    deleteMatrix(mat7);
    deleteMatrix(C);
    
    return 0;
}