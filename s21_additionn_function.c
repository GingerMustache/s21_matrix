#include "s21_matrix.h"

// освобождение памяти матрицы
void free_matrix(matrix_t *matrix) {
  if (matrix) {
    for (int i = 0; i < matrix->rows; i++) {
      free(matrix->matrix[i]);
    }
    free(matrix->matrix);
  } else {
    return;
  }
}