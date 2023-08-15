#include <stdexcept>
#include <math.h>
#include <iostream>


class S21Matrix {
    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other) noexcept;
        ~S21Matrix();

        int getRows() const noexcept;
        int getColumns() const noexcept;
        void setRows(int rows);
        void setColumns(int columns);

        void sumMatrix(const S21Matrix& other); 
        bool eqMatrix(const S21Matrix& other) const;
        void subMatrix(const S21Matrix& other);
        void mulNumber(const double num) noexcept;
        void mulMatrix(const S21Matrix& other);

        S21Matrix transpose() const noexcept;
        S21Matrix calcComplements() const;
        double determinant() const;
        S21Matrix inverseMatrix() const;

        S21Matrix operator+(const S21Matrix& other) const;
        S21Matrix operator-(const S21Matrix& other) const;
        S21Matrix operator*(const S21Matrix& other) const;
        S21Matrix operator*(double num) const;

        S21Matrix &operator+=(const S21Matrix& other);
        S21Matrix &operator-=(const S21Matrix& other);
        S21Matrix &operator*=(const S21Matrix& other);
        S21Matrix &operator*=(double num) noexcept;

        S21Matrix operator=(const S21Matrix& other);
        S21Matrix operator=(S21Matrix&& other) noexcept;

        bool operator==(const S21Matrix &other) const noexcept;
        double &operator()(int i, int j);
        const double &operator()(int i, int j) const;
    
    protected:
        S21Matrix minorMatrix(int row, int col) const;

    private:
        static const double k_EPS_MATRIX_EQ = 1e-07;
        int rows_, cols_;
        double **matrix_;

};