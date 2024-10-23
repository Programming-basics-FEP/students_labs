#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    // Введення довжин сторін
    printf("Введіть довжини сторін трикутника: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Перевірка на існування трикутника
    if (a + b > c && a + c > b && b + c > a) {
        // Визначення типу за сторонами
        if (a == b && b == c) {
            printf("Трикутник рівносторонній\n");
        } else if (a == b || b == c || a == c) {
            printf("Трикутник рівнобедрений\n");
        } else {
            printf("Трикутник різносторонній\n");
        }

        // Визначення типу за кутами
        double a2 = a * a, b2 = b * b, c2 = c * c;
        if (fabs(a2 + b2 - c2) < 1e-6 || fabs(a2 + c2 - b2) < 1e-6 || fabs(b2 + c2 - a2) < 1e-6) {
            printf("Трикутник прямокутний\n");
        } else if (a2 + b2 > c2 && a2 + c2 > b2 && b2 + c2 > a2) {
            printf("Трикутник гострокутний\n");
        } else {
            printf("Трикутник тупокутний\n");
        }
    } else {
        printf("Трикутник з такими сторонами не існує.\n");
    }

    return 0;
}

