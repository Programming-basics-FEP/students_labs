#include <math.h>
#include <stdio.h>

double equation(double x, int N, int A) { return N * x + A; }

double bisection(double a, double b, int N, int A, double tol) {
  double mid = 0;

  while ((b - a) / 2.0 > tol) {
    mid = (a + b) / 2.0;
    if (equation(mid, N, A) == 0.0) {
      return mid; // точний розв'язок
    } else if (equation(a, N, A) * equation(mid, N, A) < 0) {
      b = mid;
    } else {
      a = mid;
    }
  }

  return (a + b) / 2.0; // наближений розв'язок
}

int main() {
  int N, A;
  double tol = 1e-6;        // точність
  double a = -100, b = 100; // інтервал

  // Введення N та A з перевіркою
  do {
    printf("Введіть N (порядковий номер > 1) і A (вік > 1): ");
    scanf("%d %d", &N, &A);
    if (N <= 1 || A <= 1) {
      printf("Помилка: N та A повинні бути більше 1!\n");
    }
  } while (N <= 1 || A <= 1);

  // Перевірка на існування розв'язку
  if (equation(a, N, A) * equation(b, N, A) > 0) {
    printf("Рівняння не має розв'язку в інтервалі [%lf, %lf]\n", a, b);
  } else {
    double result = bisection(a, b, N, A, tol);
    printf("Розв'язок рівняння N*x + A = 0, x= %.6f\n", result);
  }

  return 0;
}
