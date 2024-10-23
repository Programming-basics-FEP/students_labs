#include <stdio.h>

int main() {
    int num1, num2;

    // Введення двох чисел з клавіатури
    printf("Введіть перше число: ");
    scanf("%d", &num1);
    printf("Введіть друге число: ");
    scanf("%d", &num2);

    // Використання тернарного оператора для порівняння
    (num1 > num2) ? printf("%d більше за %d\n", num1, num2) :
    (num1 < num2) ? printf("%d менше за %d\n", num1, num2) :
                    printf("%d дорівнює %d\n", num1, num2);

    return 0;
}