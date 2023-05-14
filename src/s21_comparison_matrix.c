#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int output = COMP_SUCCESS;

  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && output == COMP_SUCCESS; i++) {
      for (int j = 0; j < A->columns && output == COMP_SUCCESS; j++) {
        if (A->matrix[i][j] == B->matrix[i][j]) {
          output = COMP_SUCCESS;
        } else {
          output = COMP_FAILURE;
        }
      }
    }
  } else {
    output = COMP_FAILURE;
  }

  return output;
}
