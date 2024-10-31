
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findMinMaxAndSum(int arr[], int size, int* min, int* max, int* sum) {
    *min = arr[0];
    *max = arr[0];
    *sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
        *sum += arr[i];
    }
}

int main() {
    int arr[20];
    int min, max, sum;

    srand(time(0));
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;  // Генеруємо числа від 0 до 99
    }

    findMinMaxAndSum(arr, 20, &min, &max, &sum);

    printf("Масив з 20 випадкових чисел:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Мінімальне значення: %d\n", min);
    printf("Максимальне значення: %d\n", max);
    printf("Сума: %d\n", sum);

    return 0;
}
