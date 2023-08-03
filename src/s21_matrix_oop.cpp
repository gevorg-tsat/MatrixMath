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