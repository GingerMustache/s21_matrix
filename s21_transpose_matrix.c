#include "s21_matrix.h"

// Транспонирование матрицы  Aij -> Aji
int s21_transpose(matrix_t *A, matrix_t *result) {
  int output = CONVERSATION_OK;

  if (!s21_check_matrix(A)) {
    output = s21_create_matrix(A->columns, A->rows, result);
    if (!output) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}
