#include <stdio.h>

int main() {
    int num = 42;
    float fnum = 3.14159;
    char ch = 'A';
    char *str = "Hello, world!";
    int *ptr = &num;

    printf("Ціле число:\n");
    printf("Десятковий: %d\n", num);
    printf("Двійковий: %b\n", num);  // Для двійкового представлення може знадобитися gcc з опцією -std=c99 або новішою
    printf("Вісімковий: %o\n", num);
    printf("Шістнадцятковий: %x\n", num);
    printf("Шістнадцятковий (великі літери): %X\n\n", num);

    printf("Дійсне число:\n");
    printf("З плаваючою комою: %f\n", fnum);
    printf("Експоненційна форма: %e\n", fnum);
    printf("Гнучка форма: %g\n\n", fnum);

    printf("Символ: %c\n", ch);
    printf("Стрічка: %s\n", str);
    printf("Вказівник: %p\n", ptr);

    return 0;
}
