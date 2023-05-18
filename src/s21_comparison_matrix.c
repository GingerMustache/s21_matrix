#include "s21_matrix.h"

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int output = COMP_SUCCESS;

  if (!s21_check_matrix(A) && !s21_check_matrix(B) &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && output; i++) {
      for (int j = 0; j < A->columns && output; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          output = COMP_FAILURE;
        }
      }
    }
  } else {
    output = COMP_FAILURE;
  }
  return output;
}
