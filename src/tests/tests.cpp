#include "tests.h"

void fill_matrix_from_array(S21Matrix &matr, double *arr, int arr_size) {
    int arr_pointer = 0;
    for (int i = 0; i < matr.getRows(); i++) {
        for (int j = 0; j < matr.getColumns() && arr_pointer < arr_size; j++) {
            matr(i, j) = arr[arr_pointer++];
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
