#include "s21_matrix.h"

// int main() {
//   matrix_t A = {0};
//   matrix_t B = {0};
//   matrix_t Z = {0};
//   matrix_t X = {0};

//   s21_create_matrix(4, 2, &A);
//   s21_init_matrix(-5.0, &A);
//   printf("first num\n");
//   s21_display_matrix(&A);
//   printf("result\n");

//   s21_create_matrix(2, 4, &B);
//   s21_init_matrix(1.0, &B);
//   printf("second num\n");
//   s21_display_matrix(&B);
//   printf("result\n");

//   s21_mult_matrix(&A, &B, &Z);
//   printf("result\n");
//   s21_display_matrix(&Z);

//   s21_create_matrix(4, 4, &X);

//   X.matrix[0][0] = -25.0;
//   X.matrix[0][1] = -34.0;
//   X.matrix[0][2] = -43.0;
//   X.matrix[0][3] = -52.0;
//   X.matrix[1][0] = -13.0;
//   X.matrix[1][1] = -18.0;
//   X.matrix[1][2] = -23.0;
//   X.matrix[1][3] = -28.0;
//   X.matrix[2][0] = -1.0;
//   X.matrix[2][1] = -2.0;
//   X.matrix[2][2] = -3.0;
//   X.matrix[2][3] = -4.0;
//   X.matrix[3][0] = 11.0;
//   X.matrix[3][1] = 14.0;
//   X.matrix[3][2] = 17.0;
//   X.matrix[3][3] = 20.0;
//   printf("need result\n");
//   s21_display_matrix(&X);
//   printf("eq = %d\n", s21_eq_matrix(&X, &Z));
// }
