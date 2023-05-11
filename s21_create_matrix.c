#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int output = CONVERSATION_ERROR;

  if (result) {
    output = CONVERSATION_OK;
    int **matrix = (int **)calloc(rows, sizeof(int *));

    if (matrix) {
      for (int i = 0; i < rows && !output; i++) {
        matrix[i] = (int *)calloc(columns, (sizeof(int)));
        if (matrix[i] == NULL) {
          output = CONVERSATION_ERROR;
        }
      }
    } else {
      output = CONVERSATION_ERROR;
    }
  }
  return (output);
}