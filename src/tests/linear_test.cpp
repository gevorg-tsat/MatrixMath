#include "tests.h"

TEST(TestLinear, SubtestTranspose) {
    S21Matrix mat = S21Matrix(3, 1);
    S21Matrix mat2 = S21Matrix(1, 3);
    double tmp1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp1, 16);
    fill_matrix_from_array(mat2, tmp1, 16);
    ASSERT_EQ(mat.transpose() == mat2, true);
}

TEST(TestLinear, SubtestCalcComplements) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp1[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
    double tmp2[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
    fill_matrix_from_array(mat, tmp1, 9);
    fill_matrix_from_array(mat2, tmp2, 9);
    ASSERT_EQ(mat.calcComplements() == mat2, true);
}

TEST(TestLinear, SubtestCalcComplementsError) {
    S21Matrix mat = S21Matrix(3, 2);
    double tmp1[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
    fill_matrix_from_array(mat, tmp1, 9);
    ASSERT_THROW(mat.calcComplements(), std::invalid_argument);
}

TEST(TestLinear, SubtestDeterminant1) {
    S21Matrix mat = S21Matrix(4, 4);
    double tmp1[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    fill_matrix_from_array(mat, tmp1, 16);
    ASSERT_EQ(mat.determinant(), 567);
}

TEST(TestLinear, SubtestDeterminant2) {
    S21Matrix mat = S21Matrix(4, 4);
    double tmp1[16] = {-9, 2, 2, 9, 1, 9, -3, 4, 2, -9, 2, 2, 9, 5, -5, 9};
    fill_matrix_from_array(mat, tmp1, 16);
    double diff = fabs(mat.determinant() - (double)-483);
    if (diff <= 1e-7) {
        ASSERT_EQ(1, 1);
    } else {
        ASSERT_EQ(1, 0);
    }
}

TEST(TestLinear, SubtestDeterminantError) {
    S21Matrix mat = S21Matrix(4, 3);
    double tmp1[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    fill_matrix_from_array(mat, tmp1, 16);
    ASSERT_THROW(mat.determinant(), std::invalid_argument);
}

TEST(TestLinear, SubtestInverseMatrix) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double tmp2[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
    fill_matrix_from_array(mat, tmp1, 9);
    fill_matrix_from_array(mat2, tmp2, 9);
    ASSERT_EQ(mat.inverseMatrix() == mat2, true);
}

TEST(TestLinear, SubtestInverseMatrixError1) {
    S21Matrix mat = S21Matrix(3, 2);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    fill_matrix_from_array(mat, tmp1, 9);
    ASSERT_THROW(mat.inverseMatrix(), std::invalid_argument);
}

TEST(TestLinear, SubtestInverseMatrixError2) {
    S21Matrix mat = S21Matrix(3, 3);
    double tmp1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_matrix_from_array(mat, tmp1, 9);
    ASSERT_THROW(mat.inverseMatrix(), std::invalid_argument);
}
