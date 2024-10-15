#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void full_arr(int* arr, int sz) {
    for (int i = 0; i < sz; i++) {
        arr[i] = rand() % 100;
    }
}

void show_arr(int* arr, int sz) {
  for (int i = 0; i<sz; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
}

void task_three(int* arr, int sz) {
  int min = arr[0];
  int max = arr[0];
  int sum = arr[0];
  for (int i = 1; i<sz; i++) {
    if (min > arr[i]) min = arr[i];
    if (max < arr[i]) max = arr[i];
    sum += arr[i];
  }
  show_arr(arr, sz);
  printf("Мінімальне число з масиву - %d\n", min);
  printf("Максимальне число з масиву - %d\n", max);
  printf("Сума усіх чисел - %d\n", sum);
}

int* task_two_f(int arr[], int sz) {
  return (sz>=10) ? &arr[9] : NULL;
}

int* task_two_s(int arr[][10], int sz_f, int sz_s) {
  return (sz_f > 4 && sz_s > 5) ? &arr[4][5] : NULL;
}


int main() {
    srand(time(NULL));

    int arr[10];
    full_arr(arr, 10);

    printf("---| З А В Д А Н Н Я  1 |---\n");
    show_arr(arr, 10);
    printf("\n\n");

    printf("---| З А В Д А Н Н Я  2 |---\n");
    int arr_s[10][10];
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        arr_s[i][j] = rand() % 100;
      }
    }
    printf("%ls", task_two_f(arr, 10));
    printf("%ls", task_two_s(arr_s, 10, 10));
    printf("\n\n");

    printf("---| З А В Д А Н Н Я  3 |---\n");
    int arr_t2[20];
    full_arr(arr_t2, 20);
    task_three(arr_t2, 20);
    return 0;
}
