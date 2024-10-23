#include <stdio.h>


int main() {
    int a = printf("Введіть перше число:\n");
    scanf("%d", &a);
    int b = printf("Введіть друге число:\n");
    scanf("%d", &b);
    int result;

    printf("Арифметичні оператори:\n");
    printf("a = %d, b = %d\n", a, b);

    // Додавання
    result = a + b;
    printf("a + b = %d\n", result);

    // Віднімання
    result = a - b;
    printf("a - b = %d\n", result);

    // Множення
    result = a * b;
    printf("a * b = %d\n", result);

    // Ділення
    result = a / b;
    printf("a / b = %d\n", result);

    // Остача від ділення
    result = a % b;
    printf("a %% b = %d\n", result);

    printf("\nЛогічні оператори:\n");

    // Логічне AND
    printf("(a && b) = %d\n", a && b);

    // Логічне OR
    printf("(a || b) = %d\n", a || b);

    // Логічне NOT
    printf("!a = %d\n", !a);

    printf("\nПобітові оператори:\n");
    printf("a в двійковому вигляді: %b\n", a);
    printf("b в двійковому вигляді: %b\n", b);


    // Побітове AND
    result = a & b;
    printf("a & b = %b\n", result);

    // Побітове OR
    result = a | b;
    printf("a | b = %b\n", result);

    // Побітове XOR
    result = a ^ b;
    printf("a ^ b = %b\n", result);

    // Побітове доповнення
    result = ~a;
    printf("~a = %b\n", result);

    // Побітовий зсув вліво
    result = a << 1;
    printf("a << 1 = %b\n", result);
    

    // Побітовий зсув вправо
    result = a >> 1;
    printf("a >> 1 = %b\n", result);

    return 0;
}