#include <stdio.h>
#include <math.h>

double solveEquation(double N, double A, double left, double right, double epsilon) {
    double middle;

    while (fabs(right - left) > epsilon) {
        middle = (left + right) / 2;
        double value = N * middle + A;

        if (value == 0) {
            return middle;
        } else if (value > 0) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return middle;
}

int main() {
    double N, A;
    printf("Введіть ваш порядковий номер у журналі (N): ");
    scanf("%lf", &N);

    printf("Введіть ваш вік (А): ");
    scanf("%lf", &A);

    double result = solveEquation(N, A, -100, 100, 0.0001);
    printf("Розв’язок рівняння %lf * x + %lf = 0: x = %.4lf\n", N, A, result);

    return 0;
}
