#include "tests.h"

TEST(TestClass, SubtestInitNull) {
    S21Matrix mat;
    double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    ASSERT_EQ(mat.getRows(), 1);
    ASSERT_EQ(mat.getColumns(), 1);
    fill_matrix_from_array(mat, tmp, 16);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getColumns(); j++) {
            ASSERT_EQ(mat(i, j), tmp[i * mat.getColumns() + j]);
        }
    }
}

TEST(TestClass, SubtestInitArgs) {
    S21Matrix mat = S21Matrix(4, 4);
    double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    ASSERT_EQ(mat.getRows(), 4);
    ASSERT_EQ(mat.getColumns(), 4);
    fill_matrix_from_array(mat, tmp, 16);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getColumns(); j++) {
            ASSERT_EQ(mat(i, j), tmp[i * mat.getColumns() + j]);
        }
    }
}

TEST(TestClass, SubtestInitOutOfRange) {
    EXPECT_ANY_THROW(S21Matrix(-1, 4));
}

TEST(TestClass, SubtestCopy) {
    S21Matrix mat = S21Matrix(4, 4);
    double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    fill_matrix_from_array(mat, tmp, 16);
    S21Matrix mat2 = S21Matrix(mat);
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestClass, SubtestMove) {
    S21Matrix mat = S21Matrix(4, 4);
    double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
    fill_matrix_from_array(mat, tmp, 16);
    S21Matrix mat2 = S21Matrix(std::move(mat));
    ASSERT_EQ(mat2.getRows(), 4);
    ASSERT_EQ(mat2.getColumns(), 4);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getColumns(); j++) {
            ASSERT_EQ(mat2(i, j), tmp[i * mat.getColumns() + j]);
        }
    }
    ASSERT_EQ(mat.getRows(), 0);
    ASSERT_EQ(mat.getColumns(), 0);
}

TEST(TestClass, SubtestgetRows) {
    S21Matrix mat = S21Matrix(4, 3);
    ASSERT_EQ(mat.getRows(), 4);
}

TEST(TestClass, SubtestgetColumns) {
    S21Matrix mat = S21Matrix(3, 4);
    ASSERT_EQ(mat.getColumns(), 4);
}

TEST(TestClass, SubtestsetRows) {
    S21Matrix mat = S21Matrix(3, 4);
    S21Matrix mat2 = S21Matrix(4, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 0, 0, 0};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    mat.setRows(4);
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestClass, SubtestsetRowsError) {
    S21Matrix mat = S21Matrix(3, 4);
    EXPECT_ANY_THROW(mat.setRows(-1));
}

TEST(TestClass, SubtestSetCols) {
    S21Matrix mat = S21Matrix(4, 3);
    S21Matrix mat2 = S21Matrix(4, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 0, 10, 11, 12, 0};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    mat.setColumns(4);
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestClass, SubtestSetColsError) {
    S21Matrix mat = S21Matrix(3, 4);
    EXPECT_ANY_THROW(mat.setColumns(-1));
}

TEST(TestClass, SubtestGetValue) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    ASSERT_EQ(mat(0, 0), 1);
}

TEST(TestClass, SubtestGetValueError) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    EXPECT_ANY_THROW(mat(10, 3));
}

TEST(TestClass, SubtestSetValue) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    mat(0, 0) = 0;
    ASSERT_EQ(mat(0, 0), 0);
}

TEST(TestClass, SubtestSetValueError) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    EXPECT_ANY_THROW(mat(10, 3) = 0);
}

TEST(TestClass, SubtestSetCopyMatrix) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    S21Matrix mat2 = mat;
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestClass, SubtestSetMatrix) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    S21Matrix mat2 = mat;
    ASSERT_EQ(mat.eqMatrix(mat2), true);
}

TEST(TestClass, SubtestMoveMatrix) {
    S21Matrix mat = S21Matrix(3, 4);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    S21Matrix mat2 = std::move(mat);
    ASSERT_EQ(mat2.getRows(), 3);
    ASSERT_EQ(mat2.getColumns(), 4);
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getColumns(); j++) {
            ASSERT_EQ(mat2(i, j), tmp[i * mat.getColumns() + j]);
        }
    }
    ASSERT_EQ(mat.getRows(), 0);
    ASSERT_EQ(mat.getColumns(), 0);
}

TEST(TestClass, SubtestSum) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    S21Matrix mat4 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat4 = mat + mat2;
    ASSERT_EQ(mat4.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestSub) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    S21Matrix mat4 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat4 = mat - mat2;
    ASSERT_EQ(mat4.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestMulNum) {
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
    mat4 = mat * 0;
    ASSERT_EQ(mat4.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestMulMat) {
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
    mat4 = mat * mat;
    ASSERT_EQ(mat4.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestEqTrue) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp, 16);
    ASSERT_EQ(mat == mat2, true);
}

TEST(TestClass, SubtestEqFalse) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp, 16);
    mat2(0, 0) = 0;
    ASSERT_EQ(mat == mat2, false);
}

TEST(TestClass, SubtestSumEq) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat += mat2;
    ASSERT_EQ(mat.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestSubEq) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat -= mat2;
    ASSERT_EQ(mat.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestMulNumEq) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat *= 0;
    ASSERT_EQ(mat.eqMatrix(mat3), true);
}

TEST(TestClass, SubtestMulMatEq) {
    S21Matrix mat = S21Matrix(3, 3);
    S21Matrix mat2 = S21Matrix(3, 3);
    S21Matrix mat3 = S21Matrix(3, 3);
    double tmp[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double tmp3[16] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    fill_matrix_from_array(mat, tmp, 16);
    fill_matrix_from_array(mat2, tmp2, 16);
    fill_matrix_from_array(mat3, tmp3, 16);
    mat *= mat;
    ASSERT_EQ(mat.eqMatrix(mat3), true);
}
