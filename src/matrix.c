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
    for (i = 0; i < mat->row; i++) 
    {
        for (j = 0; j < mat->column; j++)
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

Matrix* addScalar(const Matrix* A, const DATA_TYPE b)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    Matrix* C = copyMatrix(A);
    
    INT  i;
    for (i = 0; i < (A->column * A->row); i++)
    {
        C->data[i] = C->data[i] + b;
    }

    return C;

}

Matrix* subScalar(const Matrix* A, const DATA_TYPE b)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    Matrix* C = addScalar(A, -1 * b);

    return C;

}

Matrix* multiplyScalar(const Matrix* A, const DATA_TYPE b)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    Matrix* C = copyMatrix(A);
    
    INT  i;
    for (i = 0; i < (A->column * A->row); i++)
    {
        C->data[i] = C->data[i] * b;
    }
    return C;
}


DATA_TYPE maxelem(const Matrix* A)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    DATA_TYPE max = A->data[0];
    INT i;
    for ( i = 0; i < (A->column * A->row); i++)
	{
		if (max < A->data[i])
		{
			max = A->data[i];
		}
	}

    return max;
}

DATA_TYPE minelem(const Matrix* A)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    DATA_TYPE min = A->data[0];
    INT i;
    for ( i = 0; i < (A->column * A->row); i++)
	{
		if (min > A->data[i])
		{
			min = A->data[i];
		}
	}

    return min;
}

Matrix* mulMatrix(const Matrix* A, const Matrix* B)
{
    if (A == NULL || B == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    if (A->column != B->row)
    {
        ERROR_SIZE_MATCH;
        return NULL;
    }

    INT i, j, k, size;
    size = A->row * B->column;
    DATA_TYPE c_data[size];
    INT C_index = 0;
    DATA_TYPE C_element = 0;

    for(i=0; i<A->row;i++){
        for(j=0;j<B->column;j++){
            for(k=0; k<A->column; k++){
                C_element += A->data[(i*A->column) + k] * B->data[(k*B->column) + j];
            };
            c_data[C_index] = C_element;
            C_index += 1;
            C_element = 0;
        };
    };
    
    Matrix* C = createMatrix( A->row, B->column, size, c_data);

    return C;

}

// transposed matrix

Matrix* transpMatrix(const Matrix* A)
{
    if (A == NULL)
    {
        ERROR_INPUT_POINTER;
        return NULL;
    }

    INT i, j, size;
    size = A->row * A->column;
    DATA_TYPE B_data[size];
    INT B_index = 0;
    for(i=0; i<A->column; i++){
        for(j=0; j<A->row; j++){
            B_data[B_index] = A->data[j*A->column + i];
            B_index += 1;
        }
    }
    
    Matrix* B = createMatrix( A->column, A->row, size, B_data);

    return B;

}

// identity matrix
Matrix* identityMatrix(const INT side)
{
    INT i, j;
    INT size = side * side;
    DATA_TYPE one = 1.0, zero=0.0;
    DATA_TYPE data[size];

    for (j = 0; j < size; j++)//c or cpp language
	{
		data[j] = zero;
	}
    for(i=0; i<side; i++){
        data[i*side + i] = one;
    };
    
    Matrix* mat = createMatrix(side, side, size, data);

    return mat;

}