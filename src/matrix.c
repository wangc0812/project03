#include "matrix.h"
#include "define.h"

Matrix* Matrix_create(INT row, INT column, INT elenum, DATA_TYPE *data) 
{
    //Generate Matrix Struct
    
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
        Matrix* mat = NULL;
        mat = (Matrix *) malloc(sizeof(Matrix));
        mat->row = row;
        mat->column = column;
        mat->data = (DATA_TYPE *) malloc((mat_size) * sizeof(DATA_TYPE));
   
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