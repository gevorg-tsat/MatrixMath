#include "tests.h"

TEST(TestArithmetic, SubtestSum) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat.sumMatrix(mat2);
    ASSERT_EQ(mat == mat3, true);
}

TEST(TestArithmetic, SubtestSumError) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(2, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    EXPECT_ANY_THROW(mat.sumMatrix(mat2));
}

TEST(TestArithmetic, SubtestSub) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat.subMatrix(mat2);
    ASSERT_EQ(mat == mat3, true);
}

TEST(TestArithmetic, SubtestSubError) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(2, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    EXPECT_ANY_THROW(mat.subMatrix(mat2));
}

TEST(TestArithmetic, SubtestMulNum) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    S21Matrix mat4 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat.mulNumber(0);
    ASSERT_EQ(mat.eqMatrix(mat3), true);
}

TEST(TestArithmetic, SubtestMulMatrix) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    S21Matrix mat4 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat.mulMatrix(mat);
    ASSERT_EQ(mat == mat3, true);
}

TEST(TestArithmetic, SubtestMulMatrixError) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(2, 2);
    S21Matrix mat3 = S21Matrix(3, 3);
    S21Matrix mat4 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    EXPECT_ANY_THROW(mat.mulMatrix(mat2));
}
