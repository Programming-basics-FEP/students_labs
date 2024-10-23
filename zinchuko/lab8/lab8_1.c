#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
  srand(time(0));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
}

int main() {
  int arr[10];
  generateRandomArray(arr, 10);

  printf("Масив з 10 випадкових чисел:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

