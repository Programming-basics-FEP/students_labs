#include <stdio.h>

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1; // Отримуємо кожен біт
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    int a = 12;  // 1100 в двійковому
    int b = 10;  // 1010 в двійковому

    // Арифметичні оператори
    printf("a = %d, b = %d\n", a, b);
    printf("Сума: a + b = %d\n", a + b); // Додавання
    printf("Різниця: a - b = %d\n", a - b); // Віднімання
    printf("Добуток: a * b = %d\n", a * b); // Множення
    printf("Частка: a / b = %d\n", a / b); // Ділення
    printf("Залишок від ділення: a %% b = %d\n", a % b); // Залишок

    // Логічні оператори
    printf("Логічне І (&&): (a > b) && (b < 20) = %d\n", (a > b) && (b < 20)); // Логічне І
    printf("Логічне АБО (||): (a < b) || (b < 20) = %d\n", (a < b) || (b < 20)); // Логічне АБО
    printf("Логічне НЕ (!): !(a > b) = %d\n", !(a > b)); // Логічне НЕ

    // Побітові оператори
    printf("\nПобітові оператори:\n");
    printf("a = %d, b = %d\n", a, b);

    printf("a AND b: a & b = %d\n", a & b); // Побітове І
    printf("a OR b: a | b = %d\n", a | b); // Побітове АБО
    printf("a XOR b: a ^ b = %d\n", a ^ b); // Побітове виключне АБО
    printf("NOT a: ~a = %d\n", ~a); // Побітове НЕ

    // Зсуви
    printf("Зсув вліво: a << 2 = %d\n", a << 2); // Зсув вліво
    printf("Зсув вправо: a >> 2 = %d\n", a >> 2); // Зсув вправо

    // Виведення двійкового представлення
    printf("\nДвійкове представлення:\n");
    printf("a (в двійковому): ");
    printBinary(a);
    printf("b (в двійковому): ");
    printBinary(b);
    printf("a & b (в двійковому): ");
    printBinary(a & b);
    printf("a | b (в двійковому): ");
    printBinary(a | b);
    printf("a ^ b (в двійковому): ");
    printBinary(a ^ b);
    printf("~a (в двійковому): ");
    printBinary(~a);

    return 0;
}
