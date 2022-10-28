#include "matrix.h"
#include "define.h"

Matrix* createMatrix(INT row, INT column, INT elenum, DATA_TYPE* data) 
{
    //Generate Matrix Struct 
    //Please remember to free the memory due to dynamic allocate
    
    if (row <= 0 || column <= 0)
    {
        ERROR_INPUT_INPUTPARA;
        return NULL;
    }

    if (data == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }
    
    
    INT mat_size = row * column;

    if (mat_size == elenum)
    {
        Matrix* mat = MALLOC(1, Matrix);
        mat->row = row;
        mat->column = column;
        mat->data = MALLOC(mat_size, DATA_TYPE);

        if (mat == NULL || mat->data == NULL)
        {
            free(mat);
            mat = NULL;

            free(mat->data);
            mat->data = NULL;

            ERROR_MEM_ALLOCATE;
            
            return NULL;
        }

        INT i;
        for (i = 0; i < mat_size; i++) 
        {
            mat->data[i] = data[i];
        }

        return mat;
  
    }
    else
    {
        printf("ERROR: the number of data does not match the matrix size \n");
        
        return NULL;
    }
    
}

VOID deleteMatrix(Matrix* mat)
{
    if (mat == NULL)
    {
        ERROR_INPUT_POINTER;
        return;
    }
    
    FREE(mat);
}

VOID printMatrix(const Matrix* mat) 
{
    //Print Matrix

    if (mat == NULL)
    {
        ERROR_INPUT_POINTER;
        return;
    }

    INT i, j;
    for (i = 0; i < mat->column; i++) 
    {
        for (j = 0; j < mat->row; j++)
        {
            printf(PRECISION, mat->data[i * (mat->column) + j]);
        }
        printf("\n");
    }

    return;
}

Matrix* copyMatrix(const Matrix* mat_src) 
{
    //Copy Matrix
    if (mat_src == NULL)
    {
       ERROR_INPUT_POINTER;
       return NULL;
    }

    INT elenum = mat_src->row * mat_src->column;
    Matrix* mat_copy = createMatrix(mat_src->row, mat_src->column, elenum, mat_src->data);
    
    return mat_copy;
}

VOID array_sum(const DATA_TYPE* a, const DATA_TYPE* b, DATA_TYPE* sum, INT length)
{
    if (a == NULL || b == NULL || sum == NULL)
    {
        ERROR_INPUT_POINTER;
        return;
    }

    INT  i;
    for (i = 0; i < length; i++)
    {
        sum[i] = a[i] + b[i];
    }

    return;
}

VOID array_sub(const DATA_TYPE* a, const DATA_TYPE* b, DATA_TYPE* sub, INT length)
{
    if (a == NULL || b == NULL || sub == NULL)
    {
        ERROR_INPUT_POINTER;
        return;
    }

    INT  i;
    for (i = 0; i < length; i++)
    {
        sub[i] = a[i] - b[i];
    }

    return;
}

Matrix* addMatrix(const Matrix* A, const Matrix* B)
{
    if (A == NULL || B == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    if (A->column != B->column || A->row != B->row)
    {
        ERROR_SIZE_MATCH;
        return NULL;
    }

    INT elenum = A->row * A->column;

    DATA_TYPE sum[elenum];
    array_sum(A->data, B->data, sum, elenum);

    Matrix* mat_sum =  createMatrix(A->row, A->column, elenum, sum);

    return mat_sum;  
}

Matrix* subtractMatrix(const Matrix* A, const Matrix* B)
{
    if (A == NULL || B == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    if (A->column != B->column || A->row != B->row)
    {
        ERROR_SIZE_MATCH;
        return NULL;
    }

    INT elenum = A->row * A->column;

    DATA_TYPE sub[elenum];
    array_sub(A->data, B->data, sub, elenum);

    Matrix* mat_sub = createMatrix(A->row, A->column, elenum, sub);

    return mat_sub;
}