#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows(0), cols(0), matrix(nullptr) { }

S21Matrix::S21Matrix(int rows, int cols)  {
    if (rows < 1 || cols < 1) {
        throw std::invalid_argument("Invalid value of rows or columns");
    }
    this->rows = rows;
    this->cols = cols;
    matrix = new double* [rows]();
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols]();
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows(other.rows), cols(other.cols) {
    matrix = new double* [rows]();
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = other.matrix[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept : rows(other.rows), cols(other.cols),
                                        matrix(other.matrix) {
    other.rows = 0;
    other.cols = 0;
    other.matrix = nullptr;
}

S21Matrix::~S21Matrix() {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    rows = 0;
    cols = 0;
    matrix = nullptr;
}

void S21Matrix::sumMatrix(const S21Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Not equal matrix sizes");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i][j] + other.matrix[i][j];
}

bool S21Matrix::eqMatrix(const S21Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        return false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(matrix[i][j] - other.matrix[i][j]) > EPS_MATRIX_EQ)
                return false;
        }
    }
    return true;
}

void S21Matrix::subMatrix(const S21Matrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Not equal matrix sizes");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i][j] - other.matrix[i][j];
}

void S21Matrix::mulNumber(const double num) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i][j] * num;
}

void S21Matrix::mulMatrix(const S21Matrix& other) {
    if (A->columns != B->rows)
        ;
    if (s21_create_matrix(A->rows, B->columns, result)) return INCORRECT_MATRIX;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
        }
    }
    return OK;

}