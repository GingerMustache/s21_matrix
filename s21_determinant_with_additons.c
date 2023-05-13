#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  int output = 0;
  int null_check = 1;

  if (!s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      *result = s21_find_determinant(A, &null_check);
      if (!null_check) output = CONVERSATION_ERROR;
    } else {
      output = CALCULATION_ERROR;
    }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}
// Нахождение минора матрицы треугольником
/*
index_row и index_column - это строка и столбец который мы пропускаем при
перезаписи из структуры matrix_t *matrix в matrix_t *tmp
                                    1 2 3
minor для элемента (1.1) матрицы    4 5 6   будет 5 6
                                    7 8 9         8 9
*/
double s21_minor_of_element(matrix_t *matrix, int index_row, int index_column,
                            matrix_t *tmp) {
  double result = 0;
  int flg_fill = 0;
  int min_row = 0, min_col = 0;

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      if (i != index_row && j != index_column) {
        tmp->matrix[min_row][min_col] = matrix->matrix[i][j];
        min_col++;
        flg_fill = 1;
      }
    }
    min_col = 0;
    if (flg_fill) min_row++;
  }
  return result;
}

double s21_find_determinant(matrix_t *A, int *null_check) {
  double output = 0.0;

  if (A->rows == 1) {
    output = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};

    if (null_check) {
      if (!s21_create_matrix(A->rows - 1, A->columns - 1, &tmp)) {
        for (int i = 0; i < A->columns; i++) {
          s21_minor_of_element(A, 0, i, &tmp);
          printf("\n");
          s21_display_matrix(&tmp);
          if (i % 2 == 1) {
            output -= A->matrix[0][i] * s21_find_determinant(&tmp, null_check);
          } else {
            output += A->matrix[0][i] * s21_find_determinant(&tmp, null_check);
          }
        }
        s21_remove_matrix(&tmp);
      } else {
        *null_check = 0;
      }
    }
  }
  return output;
}