#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 2. Функція для генерації масиву з 10 випадкових чисел
void task2(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// 3. Функція для отримання елемента масиву
int* task3a(int arr[], int index) {
    return (index >= 0 && index < 10) ? &arr[index] : NULL;
}

// 4. Функція для отримання елемента 2D масиву
int* task3b(int arr[12][12], int r, int c) {
    return (r >= 0 && r < 12 && c >= 0 && c < 12) ? &arr[r][c] : NULL;
}

// 5. Функція для знаходження мін, макс та суми елементів масиву
int task4(int arr[], int size, int *mn, int *mx) {
    *mn = *mx = arr[0];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < *mn) *mn = arr[i];
        if (arr[i] > *mx) *mx = arr[i];
        sum += arr[i];
    }
    return sum;
}

int main() {
    srand(time(0));

    // 2. Генерація масиву
    int arr[10];
    task2(arr, 10);

    //3.1 Отримання елемента з одномірного масиву
    int index;
    printf("Введіть індекс для масиву (0 - 9): ");
    scanf("%d", &index);
    int *el = task3a(arr, index);
    if (el)
        printf("Елемент з індексом %d: %d\n", index, *el);
    else
        printf("NULL\n");

    // 3.2 Генерація двовимірного масиву та отримання елемента
    int arr2[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            arr2[i][j] = rand() % 100;
        }
    }

    int r, c;
    printf("Введіть рядок (0 - 11) та стовпець (0 - 11): ");
    scanf("%d %d", &r, &c);
    
    if (task3b(arr2, r, c)!=NULL)
        printf("Елемент з індексом [%d][%d]: %d\n", r, c, task3b(arr2, r, c));

    // 4. Пошук мінімального, максимального та суми елементів масиву
    int arr3[20];
    task2(arr3, 20);
    int mn, mx, sum;
    sum = task4(arr3, 20, &mn, &mx);
    printf("mn: %d, mx: %d, Sum: %d\n", mn, mx, sum);

    return 0;
}
