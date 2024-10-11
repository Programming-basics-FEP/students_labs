#include <stdio.h>
#include <math.h>

void solveEq(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    if (D > 0) {
        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);
        printf("Корені: %.2f і %.2f\n", root1, root2);
    } else if (D == 0) {
        double root = -b / (2 * a);
        printf("Є один корінь: %.2f\n", root);
    } else {
        printf("Коренів немає (D менший за нуль).\n");
    }
}

int main() {
    // Використання арифметичних і логічних операторів
    int x = 5, y = 3;
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);

    // Логічні оператори
    printf("x && y = %b\n", x && y);
    printf("x || y = %b\n", x || y);
    printf("!x = %b\n", !x);

    // Виведення двійкового представлення
    printf("x в двійковому форматі: %b\n", x);
    printf("y в двійковому форматі: %b\n", y);
  
    // Побітові операції
    printf("x & y = %b (побітове AND)\n", x & y);
    printf("x | y = %b (побітове OR)\n", x | y);
    printf("x ^ y = %b (побітове XOR)\n", x ^ y);
    printf("~x = %b (побітове NOT)\n", ~x);
    printf("x << 1 = %b (зсув вліво)\n", x << 1);
    printf("x >> 1 = %b (зсув вправо)\n", x >> 1);

    // Введення числа та виведення його адреси та значення через вказівник
    int number;
    printf("Введіть число: ");
    scanf("%d", &number);
    int *ptr = &number;
    printf("Адреса змінної: %p, Значення: %d\n", (void*)ptr, *ptr);

    // Розв'язання квадратного рівняння
    double a, b, c;
    printf("Введіть коефіцієнти a, b, c для квадратного рівняння ax^2 + bx + c = 0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveEq(a, b, c);

    return 0;
}
