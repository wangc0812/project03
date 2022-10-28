#include "matrix.h"
#include "define.h"

Matrix* Matrix_create(INT row, INT column, INT elenum, DATA_TYPE* data) 
{
    //Generate Matrix Struct 
    //Please remember to free the memory due to dynamic allocate
    
    if (row <= 0 || column <= 0)
    {
        printf("ERROR:input paramter error \n");
        
        return NULL;
    }

    if (data == NULL)
    {
        printf("ERROR: input data pointer error \n");
        
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

            printf("ERROR:failed to allocate memeory \n");
            
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

VOID Matrix_print(const Matrix* mat) 
{
    //Print Matrix

    if (mat == NULL)
    {
        printf("ERROR: input data pointer error \n");
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

Matrix* Matrix_copy(const Matrix* mat_src) 
{
    //Copy Matrix
     if (mat_src == NULL)
    {
        printf("ERROR: input data pointer error \n");
        return NULL;
    }

    INT elenum = mat_src->row * mat_src->column;
    Matrix* mat_copy = Matrix_create(mat_src->row, mat_src->column, elenum, mat_src->data);
    
    return mat_copy;
}