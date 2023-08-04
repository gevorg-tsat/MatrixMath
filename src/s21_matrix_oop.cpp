#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) { }

S21Matrix::S21Matrix(int rows, int cols)  {
    if (rows < 1 || cols < 1) {
        throw std::invalid_argument("Invalid value of rows or columns");
    }
    this->rows_ = rows;
    this->cols_ = cols;
    matrix_ = new double* [rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
    // std::cout << "Copy constructor called\n";
    matrix_ = new double* [rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(other.rows_), cols_(other.cols_),
                                        matrix_(other.matrix_) {
    // std::cout << "Move constructor called\n";
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    // std::cout << "destructor called\n";
    for (int i = 0; i < rows_; i++)
        delete[] matrix_[i];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

int S21Matrix::getRows() {
    return rows_;
}

int S21Matrix::getColumns() {
    return cols_;
}

void S21Matrix::setRows(int rows) {
    S21Matrix new_matr = S21Matrix(rows, cols_);
    int min_rows = std::min(rows, rows_);
    for (int i = 0; i < min_rows; i++) {
        for (int j = 0; j < cols_; j++)
            new_matr.matrix_[i][j] = matrix_[i][j];
    }
    *this = std::move(new_matr);
}

void S21Matrix::setColumns(int columns) {
    S21Matrix new_matr = S21Matrix(rows_, columns);
    int min_cols = std::min(columns, cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < min_cols; j++)
            new_matr.matrix_[i][j] = matrix_[i][j];
    }
    *this = std::move(new_matr);
}


void S21Matrix::sumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Not equal matrix_ sizes");
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
}

bool S21Matrix::eqMatrix(const S21Matrix& other) const{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        return false;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS_MATRIX_EQ)
                return false;
        }
    }
    return true;
}

void S21Matrix::subMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Not equal matrix_ sizes");
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
}

void S21Matrix::mulNumber(const double num) {
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            matrix_[i][j] = matrix_[i][j] * num;
}

void S21Matrix::mulMatrix(const S21Matrix& other) {
    if (this->cols_ != other.rows_)
        throw std::logic_error("Amount of colummns of this matrix_ is not equal to amount of rows_ of the other matrix_");
    S21Matrix result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            result.matrix_[i][j] = 0;
            for (int k = 0; k < other.rows_; k++) {
                result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    *this = std::move(result);

}

void S21Matrix::operator=(const S21Matrix& other) {
    // std::cout << "Copy oper called\n";
    this->~S21Matrix();
    (S21Matrix) (other);
}

void S21Matrix::operator=(S21Matrix&& other) {
    // std::cout << "Move oper called\n";
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
    // std::cout << "plus oper called\n";
    S21Matrix result(*this);
    result.sumMatrix(other);
    return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
    S21Matrix result(*this);
    result.subMatrix(other);
    return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
    S21Matrix result(*this);
    result.mulMatrix(other);
    return result;
}
S21Matrix S21Matrix::operator*(double num) const {
    S21Matrix result(*this);
    result.mulNumber(num);
    return result;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix& other) {
    sumMatrix(other);
    return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix& other) {
    subMatrix(other);
    return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix& other) {
    mulMatrix(other);
    return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
    mulNumber(num);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
    return eqMatrix(other);
}

double &S21Matrix::operator()(int i, int j) {
    if (i >= rows_ || j >= cols_)
        throw std::out_of_range("index or indices are out of range of matrix_");
    if (i < 0 || j < 0)
        throw std::invalid_argument("Invalid value of row or column index");
    return matrix_[i][j];
}

const double &S21Matrix::operator()(int i, int j) const {
    if (i >= rows_ || j >= cols_)
        throw std::out_of_range("index or indices are out of range of matrix_");
    if (i < 0 || j < 0)
        throw std::invalid_argument("Invalid value of row or column index");
    return matrix_[i][j];
}

S21Matrix S21Matrix::transpose() {
    S21Matrix res(cols_, rows_);
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
        (res.matrix_)[j][i] = (matrix_)[i][j];
    return res;
}

S21Matrix S21Matrix::minorMatrix(int row, int col) const {
    if (row >= rows_ || col >= cols_)
        throw std::out_of_range("index or indices are out of range of matrix_");
    if (row < 0 || col < 0)
        throw std::invalid_argument("Invalid value of row or column index");
    S21Matrix result(rows_ - 1, cols_ - 1);
    int r = 0, c = 0;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++)
        if (row != i && col != j) {
            result.matrix_[r][c++] = matrix_[i][j];
            if (c == cols_ - 1) {
                r++, c = 0;
            }
        }
    }
    return result;
}

S21Matrix S21Matrix::calcComplements() {
    if (cols_ != rows_)
        throw std::logic_error("Complements matrix is defined only for squared matrix.");
    
    S21Matrix result(rows_, cols_);
    if (rows_ == 1) {
        result.matrix_[0][0] = 1;
        return result;
    }

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
        result.matrix_[i][j] = minorMatrix(i, j).determinant();
        int sign = 1;
        if ((i + j) % 2)
            sign = -1;
        result.matrix_[i][j] *= sign;
        }
    }
    return result;

}

double S21Matrix::determinant() {
    if (cols_ != rows_)
        throw std::logic_error("Determinant is defined only for squared matrix.");
    if (cols_ == 0 || rows_ == 0)
        throw std::invalid_argument("Empty matrix");
    if (rows_ == 1) {
        return matrix_[0][0];
    }
    double result = 1;
    S21Matrix temp(rows_, rows_);
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < rows_; j++)
            temp.matrix_[i][j] = matrix_[i][j];

    for (int i = 0; i < rows_; ++i) {
        double pivotElement = temp.matrix_[i][i];
        int pivotRow = i;
        for (int row = i + 1; row < rows_; ++row) {
            if (fabs(temp.matrix_[row][i]) > fabs(pivotElement)) {
                pivotElement = temp.matrix_[row][i];
                pivotRow = row;
            }
        }
        if (pivotElement == 0.) {
            return 0;
        }
        if (pivotRow != i) {
            double *swap = temp.matrix_[i];
            temp.matrix_[i] = temp.matrix_[pivotRow];
            temp.matrix_[pivotRow] = swap;
            result *= -1.0;
        }
        result *= pivotElement;

        for (int row = i + 1; row < rows_; ++row) {
            for (int col = i + 1; col < cols_; ++col) {
                temp.matrix_[row][col] -=
                    temp.matrix_[row][i] * temp.matrix_[i][col] / pivotElement;
            }
        }
    }
    return result;

}

S21Matrix S21Matrix::inverseMatrix() {
    if (cols_ != rows_)
        throw std::logic_error("Inverse matrix is defined only for squared matrix.");
    
    double det = determinant();
    if (fabs(det) < EPS_MATRIX_EQ) {
        throw std::logic_error("Determinant equals 0, Inverse matrix is undefined");
    }
    S21Matrix result;
    result = calcComplements();
    result = result.transpose();
    for (int i = 0; i < result.rows_; i++)
        for (int j = 0; j < result.cols_; j++)
            result.matrix_[i][j] *= (1 / det);
    return result;

}

// int main() {
//     S21Matrix m1(2, 2), m2(2, 2);
//     S21Matrix m3;
//     // m3 = m1 + m2; //move
//     // m3 = m2; // copy
//     m1(0,0) = 1;
//     m1(0, 1) = 2;
//     m1(1, 0) = 3;
//     m1(1, 1) = 4;

//     return 0;
// }