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
    // std::cout << "Copy constructor called\n";
    matrix = new double* [rows]();
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = other.matrix[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows(other.rows), cols(other.cols),
                                        matrix(other.matrix) {
    // std::cout << "Move constructor called\n";
    other.rows = 0;
    other.cols = 0;
    other.matrix = nullptr;
}

S21Matrix::~S21Matrix() {
    // std::cout << "destructor called\n";
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
    if (this->cols != other.rows)
        throw std::logic_error("Amount of colummns of this matrix is not equal to amount of rows of the other matrix");
    S21Matrix result(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < other.rows; k++) {
                result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    *this = result;

}

void S21Matrix::operator=(const S21Matrix& other) {
    // std::cout << "Copy oper called\n";
    this->~S21Matrix();
    (S21Matrix) (other);
}


void S21Matrix::operator=(S21Matrix&& other) {
    // std::cout << "Move oper called\n";
    (S21Matrix) (std::move(other));
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
    // std::cout << "plus oper called\n";
    S21Matrix result(*this);
    result.sumMatrix(other);
    return result;
}


int main() {
    S21Matrix m1(2, 2), m2(2, 2);
    S21Matrix m3;
    m3 = m1 + m2;
    return 0;
}