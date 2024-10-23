#include <stdio.h>

int main() {
  int num;
  int *ptr; // Вказівник на змінну типу int

  // Введення числа
  printf("Введіть ціле число: ");
  scanf("%d", &num);

  // Присвоюємо вказівнику адресу змінної num
  ptr = &num;

  // Виведення значення змінної та її адреси
  printf("Введене число: %d\n", num);
  printf("Адреса через вказівник: %p\n", (void *)ptr);

  return 0;
}