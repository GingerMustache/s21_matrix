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

// Матрица алгебраических дополнений
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

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int output = 0;
  double determinant = 0.0;
  matrix_t alg_add = {0};        // Надо потом почистить
  matrix_t transpose_mat = {0};  // Надо потом почистить

  if (!s21_check_matrix(A)) {
    output = s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
      return output = CONVERSATION_OK;
    } else if (A->rows == A->columns) {
      s21_determinant(A, &determinant);
      if (determinant) {
        output += s21_create_matrix(A->rows, A->columns, &alg_add);
        output += s21_create_matrix(A->rows, A->columns, &transpose_mat);
        output += s21_calc_complements(A, &alg_add);
        output += s21_transpose(&alg_add, &transpose_mat);
        if (output == 0) {
          s21_mult_number(&transpose_mat, (1 / determinant), result);
        }
        s21_remove_matrix(&alg_add);
        s21_remove_matrix(&transpose_mat);
      } else {
        output = CALCULATION_ERROR;
      }
    } else {
      output = CALCULATION_ERROR;
    }
  } else {
    output = CONVERSATION_ERROR;
  }
  return output;
}
