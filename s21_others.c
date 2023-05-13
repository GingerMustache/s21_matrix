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

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int output = CONVERSATION_OK;
  int check_null = 0;

  if (!s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      check_null += s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && check_null == 0; i++) {
        for (int j = 0; j < A->columns && check_null == 0; j++) {
          matrix_t minor = {0};
          double determinant = 0.0;
          check_null += s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          s21_minor_of_element(A, i, j, &minor);
          check_null += s21_determinant(&minor, &determinant);
          if (check_null == 0) {
            result->matrix[i][j] = pow(-1, (i + j)) * determinant;
            s21_remove_matrix(&minor);
          } else {
            output = CONVERSATION_ERROR;
          }
        }
      }
    } else {
      output = CALCULATION_ERROR;
    }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}
