#include "s21_matrix.h"

/*
Определитель матрицы равен сумме произведений элементов строки (столбца)
на соответствующие алгебраические дополнения.

Поиск определителя для матрицы A по первой строке:

    1 2 3
A = 4 5 6
    7 8 9

|A| = 1 × 5 6 - 2 × 4 6 + 3 × 4 5 = 1 × (5 × 9 - 8 × 6) -
......... 8 9       7 9       7 8

- 2 × (4 × 9 - 6 × 7) + 3 × (4 × 8 - 7 × 5)

|A| = 1 × (45 - 48) - 2 × (36 - 42) + 3 × (32 - 35) = -3 + 12 + (-9) = 0
|A| = 0

Как это работает в коде: (Все вычисления и сам алгоритм находятся в
s21_find_determinant)

matrix_t A  1 2 3
            4 5 6
            7 8 9

    1. Находим минорную подматрицу для элемента (0.0)
       matrix_t tmp  5 6
                     8 9
    2. Проверяем элемент на четность
    3. Ищем минор для элемента (0.0) matrix_t tmp = 9
    4. Проверяем на элемент четность
    5. Перемножаем элемент (0.0) в matrix_t tmp на 9 = 45
    6  Ищем минор для элемента (0.0) matrix_t tmp = 8
    7. Перемножаем элемент (0.1) в matrix_t tmp на 8 = 48
    8. Находим разницу между 45 и 48 = -3!
    9. Чистим матрицу tmp

    1.0. Находим минорную подматрицу для элемента (0.1)
         matrix_t tmp  4 6
                       7 9
    1.2. Проверяем элемент на четность
    1.3. Ищем минор для элемента (0.0) matrix_t tmp = 9
    1.4. Проверяем на элемент четность
    1.5. Перемножаем элемент (0.0) в matrix_t tmp на 9 = 36
    1.6  Ищем минор для элемента (0.0) matrix_t tmp = 7
    1.7. Перемножаем элемент (0.1) в matrix_t tmp на 8 = 42
    1.8. Находим разницу между 36 и 42 = -6!

    10. Перемножаем элемент (0.0) matrix_t A  1 * (-3)
    11. Перемножаем элемент (0.1) matrix_t A  2 * (-3)
    12. Находим разницу  1 * (-3) -  2 * (-3) = 9
    ...
    Нашли минорную матрицу для элемента (0.2) 4 7
                                              5 8
    -> нашли минор для элемента (0.0) в tmp и перемножили их = 4 * 8 = 32
    -> нашли минор для элемента (0.1) в tmp и перемножили их = 5 * 7 = 35
    -> нашли разницу мжду ними 32 - 35 = -3
    -> Перемножаем элемент (0.2) matrix_t A на полученный результат

        3 * (-3) =-9!

    13. Найдя результат из 12го пункта мы прибавляем к нему -9 = 9 + (-9) = 0!
    14. Возвращяем ответ = 0.
*/

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

// Нахождения определителя
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