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

int s21_matrix_minor(matrix_t *matrix, matrix_t *result) {
  int output = 0;
  if (!s21_check_matrix(matrix)) {
    output = s21_create_matrix(matrix->rows, matrix->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = s21_minor_of_element(matrix, i, j);
      }
    }
    // for (int i = 1; i < matrix->rows; i++) {
    //   for (int j = 1; j < matrix->columns; j++) {
    //     tmp.matrix[i - 1][j - 1] = matrix->matrix[i][j];
    //     printf("\n");
    //     s21_display_matrix(&tmp);
    //   }
    // }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}

double s21_minor_of_element(matrix_t *matrix, int index_row, int index_column) {
  double result = 0;
  int output = 0;
  matrix_t tmp = {0};
  output = s21_create_matrix(matrix->rows - 1, matrix->columns - 1, &tmp);
  if (!output) {
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        if (i != index_row && j != index_column) {
          tmp.matrix[i - 1][j - 1] = matrix->matrix[i][j];
          printf("\n");
          s21_display_matrix(&tmp);
        }
      }
    }
  }  //  дописать else
  return result;
}