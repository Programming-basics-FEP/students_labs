#include <stdio.h>
#include <stdlib.h>


int main() {
  int a = 11;
  int b = 62;
  int a_b = 0b00001011;
  int b_b = 0b00111110;
  printf("---| a = %d; b = %d | ---\n", a , b);
  printf("\n---| Арифметичні оператори |---\n");
  printf("Віднімання: %d\n", a - b);
  printf("Додавання: %d\n", a + b);
  printf("Множення: %d\n", a * b);
  printf("Ділення: %d\n", a / b);
  printf("Остача від ділення: %d\n", a % b);
  printf("Префіксний інкремент: %d\n", ++a);
  printf("Постфіксний інкремент: %d\n", a++);
  printf("Префіксний декремент: %d\n", --a);
  printf("Постфіксний декремент: %d\n", a--);
  printf("\n---| Оператори порівняння |---\n");
  printf("Більше (a > b): %d\n", (a > b));
  printf("Менше (a < b): %d\n", (a < b));
  printf("Більше рівно (a >= b): %d\n", (a >= b));
  printf("Менше рівно (a <= b): %d\n", (a <= b));
  printf("Рівно (a == b): %d\n", (a == b));
  printf("Не рівно (a != b): %d\n", (a != b));
  printf("\n---| Логічні оператори |---\n");
  printf("І (a < b) && (a != b): %d\n", ((a < b) && (a != b)));
  printf("Або (a > b) || (a == 11): %d\n", ((a > b) || (a == 11)));
  printf("Не !(a < b): %d\n", !(a < b));
  printf("\n---| Побітові оператори |---\n");
  printf("І: %d\n", a_b & b_b);
  printf("Або: %d\n", a_b | b_b);
  printf("Виключне Або (xor): %d\n", a_b ^ b_b);
  printf("Доповнення (Не): %d\n", ~a_b);
  printf("Зсув вправо: %d\n", a_b >> 1);
  printf("Зсув вліво: %d\n", a_b << 1);
  return 0;
}