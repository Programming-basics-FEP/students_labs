#include <stdio.h>
#include <math.h>

double equation(double x, int N, int A) {
    return N * x + A;
}

void bisectionMethod(int N, int A, double a, double b, double tolerance) {
    if (equation(a, N, A) * equation(b, N, A) >= 0) {
        printf("В інтервалі немає кореня або корінь не можна знайти цим методом.\n");
        return;
    }

    double c;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        if (equation(c, N, A) == 0.0) {
            break;
        } else if (equation(c, N, A) * equation(a, N, A) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    printf("x = %.5f\n", c);
}

int main() {
    int N, A;
    double tolerance = 0.00001;
    double a = -100, b = 100;

    printf("Введіть ваш порядковий номер (N): ");
    scanf("%d", &N);

    if (N == 0) {
        printf("N дорівнює 0. Bbeдіть не 0.\n");
        return 0;
    }

    printf("Введіть ваш вік у повних роках (A): ");
    scanf("%d", &A);

    bisectionMethod(N, A, a, b, tolerance);

    return 0;
}
