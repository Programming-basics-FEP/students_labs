#include <stdio.h>

int main() {
    double num1, num2;

    // Введення двох чисел
    printf("Введіть перше число: ");
    scanf("%lf", &num1);
    printf("Введіть друге число: ");
    scanf("%lf", &num2);

    // Порівняння за допомогою тернарного оператора
    (num1 > num2) ? printf("%.2lf більше ніж %.2lf\n", num1, num2) :
    (num1 < num2) ? printf("%.2lf менше ніж %.2lf\n", num1, num2) :
                    printf("%.2lf дорівнює %.2lf\n", num1, num2);

    return 0;
}
