//   matrix.cpp


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);

    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);

    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }

    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
    for(int i = 0; i < rowsM; i++)
    {
        sum_rowsM[i] = 0;
        for(int j = 0; j < colsM; j++)
            sum_rowsM[i] += matrixM[i][j];
    }
}

void Matrix::sum_of_cols()const
{
    for(int j = 0; j < colsM; j++)
        sum_colsM[j] = 0;

    for(int i = 0; i < rowsM; i++)
    {
        for(int j = 0; j < colsM; j++)
            sum_colsM[j] += matrixM[i][j];
    }
}

void Matrix::copy(const Matrix& source)
{
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }

    rowsM = source.rowsM;
    colsM = source.colsM;

    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);


    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);

    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);

    //added content past this point
    for(int i =0; i < rowsM; i++)
    {
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }

    for(int i = 0; i < rowsM; i++)
    {
        for(int j = 0; j < colsM; j++)
            matrixM[i][j] = source.matrixM[i][j];
    }
    sum_of_rows();
    sum_of_cols();
}

void Matrix::destroy()
{
    for(int i = 0; i < rowsM; i++)
        free(matrixM[i]);
    free(matrixM);

    free(sum_rowsM);
    free(sum_colsM);
}
