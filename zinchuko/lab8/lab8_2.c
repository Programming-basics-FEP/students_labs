#include <stdio.h>

// Функція для отримання вказівника на елемент одновимірного масиву
int* getElementPointer(int arr[], int index, int size) {
    if (index >= 0 && index < size) {
        return &arr[index];
    }
    return NULL;  // Якщо індекс некоректний
}

// Функція для отримання вказівника на елемент двовимірного масиву
int* get2DElementPointer(int arr[12][12], int row, int col) {
    if (row >= 0 && row < 12 && col >= 0 && col < 12) {
        return &arr[row][col];
    }
    return NULL;  // Якщо індекси некоректні
}

int main() {
    // Частина 1: Одновимірний масив
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index;

    printf("Введіть індекс (0-9) для отримання вказівника на елемент одновимірного масиву: ");
    scanf("%d", &index);

    int* ptr1 = getElementPointer(arr1, index, 10);
    if (ptr1 != NULL) {
        printf("Значення елемента на індексі %d: %d\n", index, *ptr1);
    } else {
        printf("Невірний індекс.\n");
    }

    // Частина 2: Двовимірний масив
    int arr2[12][12];
    // Заповнення масиву для прикладу
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            arr2[i][j] = i * 12 + j;
        }
    }

    int row, col;
    printf("Введіть індекси рядка та стовпця (0-11) для двовимірного масиву: ");
    scanf("%d %d", &row, &col);

    int* ptr2 = get2DElementPointer(arr2, row, col);
    if (ptr2 != NULL) {
        printf("Значення елемента [%d][%d]: %d\n", row, col, *ptr2);
    } else {
        printf("Елемент відсутній.\n");
    }

    return 0;
}

