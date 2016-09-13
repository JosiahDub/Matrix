// Matrix.cpp : Defines the entry point for the application.
//

#include "Matrix.h"

Matrix::Matrix(uint rows, uint cols):
	num_rows(rows),
	num_cols(cols)
{
	matrix = new double*[rows];
	for (uint i = 0; i < rows; ++i)
	{
		matrix[i] = new double[cols];
	}
}

Matrix::Matrix(const i_list & list) :
	num_rows(list.size()),
	num_cols(list.begin()->size())
{
	matrix = new double*[num_rows];
	int matrix_row_num = 0;
	for (auto list_row : list)
	{
		matrix[matrix_row_num] = new double[num_cols];
		int matrix_col_num = 0;
		for (auto list_num : list_row)
		{
			matrix[matrix_row_num][matrix_col_num] = list_num;
			++matrix_col_num;
		}
		++matrix_row_num;
	}
}

Matrix::Matrix(const Matrix & m) :
	num_rows(m.num_rows),
	num_cols(m.num_cols)
{
	matrix = new double*[num_rows];
	for (uint i = 0; i < num_rows; ++i)
	{
		matrix[i] = new double[num_cols];
		for (uint j = 0; j < num_cols; ++j)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (uint i = 0; i < num_cols; ++i)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

Matrix Matrix::add(double s) const
{
	for (uint i = 0; i < num_rows; ++i)
	{
		for (uint j = 0; j < num_cols; ++j)
		{
			matrix[i][j] += s;
		}
	}
	return *this;
}

Matrix Matrix::add(const Matrix & m) const
{
	for (uint i = 0; i < this->num_rows; ++i)
	{
		for (uint j = 0; j < this->num_cols; ++j)
		{
			this->matrix[i][j] += m.at(i, j);
		}
	}
	return *this;
}

/*Matrix Matrix::subtract(double s) const
{

}

Matrix Matrix::subtract(const Matrix & m) const
{

}

Matrix Matrix::multiply(double s) const
{

}

Matrix Matrix::multiply(const Matrix & m) const
{

}

Matrix Matrix::divide(double s) const
{

}

Matrix Matrix::t() const
{

}*/

const uint Matrix::numRows() const
{
	return num_rows;
}

const uint Matrix::numCols() const
{
	return num_cols;
}

double & Matrix::at(uint row, uint col)
{
	return matrix[row][col];
}

const double & Matrix::at(uint row, uint col) const
{
	return matrix[row][col];
}