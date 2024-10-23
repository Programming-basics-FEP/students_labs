#include <stdio.h>

int recursiveSum(int num) {
    if (num > 100) return 0;
    return num + recursiveSum(num + 1);
}

int main() {
    int myNumber;
    printf("Введіть ваш порядковий номер у журналі: ");
    scanf("%d", &myNumber);

    int sum = recursiveSum(myNumber);
    printf("Сума чисел від %d до 100: %d\n", myNumber, sum);

    return 0;
}

