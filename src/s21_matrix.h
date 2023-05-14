#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Результирующий код вычислений
/*
    0 - OK
    1 - Ошибка, некорректная матрица
    2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
   нельзя провести вычисления и т.д.)
*/
#define CONVERSATION_OK 0
#define CONVERSATION_ERROR 1
#define CALCULATION_ERROR 2

// Создание матриц (create_matrix)
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц (remove_matrix)
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц (eq_matrix)
int s21_eq_matrix(matrix_t *A, matrix_t *B);

#define COMP_SUCCESS 1
#define COMP_FAILURE 0

// Сложение (sum_matrix) и вычитание матриц (sub_matrix)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы (transpose)
int s21_transpose(matrix_t *A, matrix_t *result);

// Минор матрицы и матрица алгебраических дополнений (calc_complements)
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы (determinant)
int s21_determinant(matrix_t *A, double *result);

// Обратная матрица (inverse_matrix)
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//----------------------- Addition functions -----------------------//

// Заполнение матрицы числами
void s21_init_matrix(double number, matrix_t *A);

// Проверка матрицы на корректность
int s21_check_matrix(matrix_t *matrix);

// Вывод матрицы на экран
void s21_display_matrix(matrix_t *A);

// Вычисление минора элемента матрицы
double s21_minor_of_element(matrix_t *matrix, int index_row, int index_column,
                            matrix_t *tmp);

// Рекурсивное вычислени определителя
double s21_find_determinant(matrix_t *A, int *null_check);

int test_a(int *m);

#endif  // SRC_S21_MATRIX_H_
