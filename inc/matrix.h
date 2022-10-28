#ifndef  __MATRIX_H__
#define  __MATRIX_H__

#include <stdio.h>
#include "define.h"
#include <stdlib.h>

typedef struct Matrix {
    INT row;
    INT column;
    DATA_TYPE *data;
} Matrix;

Matrix* Matrix_create(INT row, INT column, INT elenum, DATA_TYPE* data);

VOID Matrix_print(const Matrix* mat);

Matrix* Matrix_copy(const Matrix* mat_src);

#endif