#include <stdio.h>
#include <stdlib.h>


int task_one(char* str) {
  int ctr = 0;
  for(int i = 0; str[i+1]!='\0'; i++) {
    ctr+=1;
  }
  return ctr;
}

int* toPoint(int x, int y) {
  int* int_ptr = (int*)malloc(2*sizeof(int));
  int_ptr[0] = x;
  int_ptr[1] = y;
  return int_ptr;
}

float addd(float a, float b) {
  return a + b;
}

float subd(float a, float b) {
  return a - b;
}

float muld(float a, float b) {
  return a * b;
}

float divd(float a, float b) {
  return b ? a/b : 0;
}

int main() {
  /// T A S K   O N E
  char* user = (char*)malloc(100*sizeof(char));
  printf("(Завданя 1)>");
  fgets(user, (100*sizeof(char)), stdin);
  int ln = task_one(user);
  printf("Довжина стрічки: %d\n\n", ln);

  /// T A S K   T W O
  printf("(Завдання 2)>");
  int* int_ptr = toPoint(10, 20);
  printf("Вказівник на точку: %p\n", int_ptr);
  printf("Точки: x = %d, y = %d\n\n", int_ptr[0], int_ptr[1]);

  /// T A S K   T H R E E
  float a, b;
  char op;
  printf("(Завдання 3)>");
  scanf("%f%c%f", &a, &op, &b);
  float (*func[4])(float, float) = { addd, subd, muld, divd };
  printf("Результат виконання: %f\n", func[(op == '+') ? 0 : (op == '-') ? 1 : (op == '*') ? 2 : 3](a, b));


  free(user);
}