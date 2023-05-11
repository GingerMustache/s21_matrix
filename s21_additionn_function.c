#include "s21_matrix.h"

// Заполнение матрицы числами
void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

int s21_check_matrix(matrix_t *matrix) {
  int output = CONVERSATION_OK;
  if (matrix->rows < 1 || matrix->columns < 1) output = CONVERSATION_ERROR;
  if (matrix->matrix == NULL) output = CONVERSATION_ERROR;
  if (matrix == NULL) output = CONVERSATION_ERROR;

  return output;
}
