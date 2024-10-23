
#include <stdio.h>

int main() {
  int N;

  while (1) {
    printf("Введіть ціле число N в межах [7; 12]: ");
    scanf("%d", &N);
    if (N >= 7 && N <= 12) {
      break;
    } else {
      printf("Будь ласка, введіть число саме в заданих межах [7; 12]\n");
    }
  }

  double numbers[12]; // Максимальний розмір масиву
  double total_sum = 0.0, average, minimum, maximum;

  for (int i = 0; i < N; i++) {
    printf("Введіть дійсне число %d: ", i + 1);
    scanf("%lf", &numbers[i]);
    total_sum += numbers[i];
  }

  average = total_sum / N;
  minimum = numbers[0];
  maximum = numbers[0];

  for (int i = 1; i < N; i++) {
    if (numbers[i] < minimum) {
      minimum = numbers[i];
    }
    if (numbers[i] > maximum) {
      maximum = numbers[i];
    }
  }

  printf("Сума введених чисел: %.2f\n", total_sum);
  printf("Середнє арифметичне: %.2f\n", average);
  printf("Мінімальне значення: %.2f\n", minimum);
  printf("Максимальне значення: %.2f\n", maximum);

  return 0;
}
