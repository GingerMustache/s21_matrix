#include "s21_matrix.h"

int main() {
  matrix_t A = {0};
  matrix_t B = {0};
  //   matrix_t D = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);
  printf("first num\n");
  s21_display_matrix(&A);

  //   s21_create_matrix(3, 4, &D);
  //   s21_init_matrix(1.0, &D);
  //   printf("second num\n");
  //   s21_display_matrix(&D);

  printf("transp = %d\n", s21_matrix_minor(&A, &B));
  printf("result num\n");
  s21_display_matrix(&B);

  //   s21_init_matrix(1.0, &B);
  //   printf("eq = %d\n", s21_eq_matrix(&B, &D));

  //   s21_create_matrix(4, 2, &A);
  //   s21_init_matrix(1.0, &A);
  //   printf("first num\n");
  //   s21_display_matrix(&A);
  //   printf("result\n");

  //   s21_create_matrix(2, 4, &B);
  //   s21_init_matrix(1.0, &B);
  //   printf("second num\n");
  //   s21_display_matrix(&B);
  //   printf("result\n");

  //   s21_display_matrix(&Z);
}
