#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int descriminand(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

void kvriv(int d, int b, int a) {
    if (d < 0) {
        printf("Рівняння коренів не має.\n");
        return;
    } else if (d == 0) {
        double x = (double)-b / (2 * a);
        printf("Корінь 1: %.2f\n", x);
    } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Корені 2: \nx1 - %.2f \nx2 - %.2f\n", x1, x2);
    }
}

int main() {
    int a, b, c;
    printf("a*x^2 + b*x + c\n");
    printf("a: ");
    scanf("%d", &a);

    if (a == 0) {
        printf("Коефіцієнт 'a' не може дорівнювати нулю.\n");
        return 1;
    }

    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    int d = descriminand(a, b, c);
    kvriv(d, b, a);
    return 0;
}
