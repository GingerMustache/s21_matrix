#include "s21_matrix.h"

// Сумма двух матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = CONVERSATION_OK;

  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      output = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
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

// Вычитание двух матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = CONVERSATION_OK;

  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      output = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int output = CONVERSATION_OK;

  if (!s21_check_matrix(A)) {
    output = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}

// Умножение матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int output = CONVERSATION_OK;

  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->columns == B->rows) {
      output = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
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
