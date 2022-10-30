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

Matrix* createMatrix(INT row, INT column, INT elenum, DATA_TYPE* data);

VOID deleteMatrix(Matrix* mat);

VOID printMatrix(const Matrix* mat);

Matrix* copyMatrix(const Matrix* mat_src);

VOID array_sum(const DATA_TYPE* a, const DATA_TYPE* b, DATA_TYPE* sum, INT length);

VOID array_sub(const DATA_TYPE* a, const DATA_TYPE* b, DATA_TYPE* sub, INT length);

Matrix* addMatrix(const Matrix* A, const Matrix* B);

Matrix* subtractMatrix(const Matrix* A, const Matrix* B);

Matrix* addScalar(const Matrix* A, const DATA_TYPE b);

Matrix* subScalar(const Matrix* A, const DATA_TYPE b);

Matrix* multiplyScalar(const Matrix* A, const DATA_TYPE b);

DATA_TYPE maxelem(const Matrix* A);

DATA_TYPE minelem(const Matrix* A);

Matrix* mulMatrix(const Matrix* A, const Matrix* B);

Matrix* transpMatrix(const Matrix* A);

Matrix* identityMatrix(const INT side);

#endif