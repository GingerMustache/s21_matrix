#include "s21_matrix.h"

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int output = CONVERSATION_ERROR;

  if (rows < 1 || columns < 1) {
    output = CONVERSATION_ERROR;
  } else {
    output = CONVERSATION_OK;
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix != NULL) {
      for (int i = 0; i < rows && !output; i++) {
        result->matrix[i] = (double *)calloc(columns, (sizeof(double)));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i; j++) free(result->matrix[j]);
          free(result->matrix);
          output = CONVERSATION_ERROR;
        }
      }
    } else {
      output = CONVERSATION_ERROR;
    }
  }
  return (output);
}

// Очистка матриц
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);

    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
