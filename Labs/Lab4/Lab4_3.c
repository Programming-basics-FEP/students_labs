#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c; // Коефіцієнти рівняння
    double discriminant, root1, root2;

    // Введення коефіцієнтів
    printf("Введіть коефіцієнт a (не може бути 0): ");
    scanf("%lf", &a);

    // Перевірка, чи a не є нулем
    if (a == 0) {
        printf("Коефіцієнт a не може бути 0 у квадратному рівнянні.\n");
        return 1; // Завершення програми з помилкою
    }

    printf("Введіть коефіцієнт b: ");
    scanf("%lf", &b);
    printf("Введіть коефіцієнт c: ");
    scanf("%lf", &c);

    // Обчислення дискримінанту
    discriminant = b * b - 4 * a * c;

    // Перевірка значення дискримінанту
    if (discriminant > 0) {
        // Два різних дійсних корені
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Два різних дійсних корені: x1 = %.2lf, x2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        // Один дійсний корінь
        root1 = -b / (2 * a);
        printf("Один дійсний корінь: x = %.2lf\n", root1);
    } else {
        // Комплексні корені
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Комплексні корені: x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
