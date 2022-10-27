#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "define.h"

int main()
{
    printf("test \n");
    INT elenum = 3;
    DATA_TYPE data[3] = {1,2,3};
    INT row =4;
    INT col =1;
    Matrix* mat =  Matrix_create(row, col, elenum, data);
    return 0;
}