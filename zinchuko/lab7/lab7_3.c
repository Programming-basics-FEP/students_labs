#include <stdio.h>
#include <math.h>

double equation(double x, int N, int A) {
    return N * x + A;
}

void bisectionMethod(int N, int A, double a, double b, double tolerance) {
    if (equation(a, N, A) * equation(b, N, A) >= 0) {
        printf("No solution in the given interval.\n");
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
    printf("x= %.5f\n", c);
}

int main() {
    int N, A;
    double tolerance = 0.00001;

    printf("Введіть ваш порядковий номер (N): ");
    scanf("%d", &N);

    if (N == 0) {
        printf("N = 0, Введіть N > 0.\n");
        return 0;
    }

    printf("Введіть скільки вам повних років (A): ");
    scanf("%d", &A);

    double a = -100, b = 100;
    bisectionMethod(N, A, a, b, tolerance);

    return 0;
}
