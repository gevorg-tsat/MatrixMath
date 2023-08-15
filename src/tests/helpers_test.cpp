#include "tests.h"

TEST(TestHelpers, SubtestEqTrue) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp, 16);
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestHelpers, SubtestEqFalse) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp, 16);
    mat2(0, 0) = 0;
    ASSERT_EQ(mat.eqMatrix(mat2), false);
}

TEST(TestHelpers, SubtestMatrixFill) {
    S21Matrix mat = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getColumns(); j++) {
            ASSERT_EQ(mat(i, j), tmp[i * mat.getColumns() + j]);
        }
    }
}