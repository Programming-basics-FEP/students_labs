#include <stdio.h>

int main() {
    int sum = 0;
    int i = 1;
    int my_number = 9; // Замість 25 вставте свій порядковий номер

    while (i <= 100) {
        if (i != my_number && i != 33) {
            sum += i;
        }
        i++;
    }

    printf("Сума: %d\n", sum);
    return 0;
}
