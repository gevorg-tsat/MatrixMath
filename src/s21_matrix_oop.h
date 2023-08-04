#include <stdexcept>
#include <math.h>
#include <iostream>

#define EPS_MATRIX_EQ 1e-07

class S21Matrix {
    private:
        int rows, cols;
        double **matrix;

    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        void sumMatrix(const S21Matrix& other); 
        bool eqMatrix(const S21Matrix& other);
        void subMatrix(const S21Matrix& other);
        void mulNumber(const double num);
        void mulMatrix(const S21Matrix& other);

        S21Matrix transpose();
        S21Matrix calcComplements();
        double determinant();
        S21Matrix inverseMatrix();

        S21Matrix operator+(const S21Matrix& other) const;
        S21Matrix operator-(const S21Matrix& other) const;
        S21Matrix operator*(const S21Matrix& other) const;
        S21Matrix operator*(double num) const;

        S21Matrix &operator+=(const S21Matrix& other);
        S21Matrix &operator-=(const S21Matrix& other);
        S21Matrix &operator*=(const S21Matrix& other);
        S21Matrix &operator*=(double num);

        void operator=(const S21Matrix& other);
        void operator=(S21Matrix&& other);

        bool operator==(const S21Matrix &other) const;
        double &operator()(int i, int j);
        const double &operator()(int i, int j) const;
};