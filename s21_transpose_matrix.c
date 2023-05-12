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

// int s21_matrix_minor(matrix_t *matrix, matrix_t *result) {
//   int output = 0;
//   if (!s21_check_matrix(matrix)) {
//     output = s21_create_matrix(matrix->rows, matrix->columns, result);
//     for (int i = 0; i < result->rows; i++) {
//       for (int j = 0; j < result->columns; j++) {
//         result->matrix[i][j] = s21_minor_of_element(matrix, i, j);
//       }
//     }
//   } else {
//     output = CONVERSATION_ERROR;
//   }
//   return output;
// }

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  int output = 0;
  if (!s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      *result = s21_get_determinant(A);
    } else {
      output = 2;
    }
  } else {
    output = 1;
  }
  return output;
}

double s21_minor_of_mat(matrix_t *matrix, int index_row, int index_column,
                        matrix_t *tmp) {
  double result = 0;
  int output = 0;
  int min_row = 0, min_col = 0;

  if (!output) {
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        if (i != index_row && j != index_column) {
          tmp->matrix[min_row][min_col] = matrix->matrix[i][j];
          printf("\n");
          s21_display_matrix(tmp);
          min_col++;
        }
      }
      min_col = 0;
      min_row = 0;
    }
  }  //  дописать else
  return result;
}

double s21_get_determinant(matrix_t *A) {
  double output = 0.0;
  // если матрица very small
  if (A->rows == 1) {
    output = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_minor_of_mat(A, 0, i, &tmp);
      if (i % 2) {
        output -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        output += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return output;
}
