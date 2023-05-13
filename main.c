#include "s21_matrix.h"

// int main() {
//   matrix_t A = {0};
//   matrix_t Z = {0};
//   matrix_t X = {0};

//   s21_create_matrix(4, 4, &A);
//   A.matrix[0][0] = 112.0;
//   A.matrix[0][1] = 243.0;
//   A.matrix[0][2] = 3.0;
//   A.matrix[0][3] = -8.0;
//   A.matrix[1][0] = 47.0;
//   A.matrix[1][1] = 51.0;
//   A.matrix[1][2] = -66.0;
//   A.matrix[1][3] = 99.0;
//   A.matrix[2][0] = -74.0;
//   A.matrix[2][1] = 85.0;
//   A.matrix[2][2] = 97.0;
//   A.matrix[2][3] = 63.0;
//   A.matrix[3][0] = -13.0;
//   A.matrix[3][1] = 79.0;
//   A.matrix[3][2] = -99.0;
//   A.matrix[3][3] = -121.0;

//   s21_calc_complements(&A, &Z);
//   s21_create_matrix(4, 4, &X);

//   X.matrix[0][0] = -2879514.0;
//   X.matrix[0][1] = -1236631.0;
//   X.matrix[0][2] = -1685096.0;
//   X.matrix[0][3] = 880697.0;
//   X.matrix[1][0] = 1162090.0;
//   X.matrix[1][1] = -714015.0;
//   X.matrix[1][2] = 4046255.0;
//   X.matrix[1][3] = -3901600.0;
//   X.matrix[2][0] = 4362897.0;
//   X.matrix[2][1] = -2049432.0;
//   X.matrix[2][2] = -532912.0;
//   X.matrix[2][3] = -1370781.0;
//   X.matrix[3][0] = 3412773.0;
//   X.matrix[3][1] = -1569493.0;
//   X.matrix[3][2] = 3144517.0;
//   X.matrix[3][3] = 1284666.0;

//   s21_display_matrix(&Z);

//   printf("res of equal = %d\n", s21_eq_matrix(&X, &Z));
// }
