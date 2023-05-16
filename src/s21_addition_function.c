#include "s21_matrix.h"

// Заполнение матрицы
void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x++) {
    for (int y = 0; y < A->columns; number += 1.0, y++)
      A->matrix[x][y] = number;
  }
}

// Проверка матрицы на корректность
// CONVERSATION_OK = 0
// CONVERSATION_ERROR = 1
int s21_check_matrix(matrix_t *matrix) {
  int res = CONVERSATION_OK;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = CONVERSATION_ERROR;
  }

  return res;
}
// Вывод матрицы на экран
// void s21_display_matrix(matrix_t *A) {
//   for (int x = 0; x < A->rows; x++) {
//     for (int y = 0; y < A->columns; y++) {
//       printf("%10lf ", A->matrix[x][y]);
//     }
//     printf("\n");
//   }
// }
