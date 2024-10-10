#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* nums[] = {
  "Один",
  "Два",
  "Три",
  "Чотири",
  "П'ять",
  "Шість",
  "Сім",
  "Вісім",
  "Дев'ять",
  "Десять",
  "Одинадцять",
  "Дванадцять",
  "Тринадцять"
};

const char* nums_d[] = {
  "Десять",
  "Двадцять",
  "Тридцять",
  "Сорок",
  "П'ятдесят",
  "Шістдесят",
  "Сімдесят",
  "Вісімдесят",
  "Дев'яносто"
};

const char* nums_h[] = {
  "Сто",
  "Двісті",
  "Триста",
  "Чотириста",
  "П'ятсот",
  "Сімсот",
  "Вісмсот",
  "Дев'ятсот",
};

typedef enum {
  True,
  False
} Bool;

typedef struct {
  int a;
  int b;
  int c;
} Triangle;

Triangle newTriangle() {
  int a, b, c;
  printf("Уведіть довжини трикутника: \n");
  printf(">>>");
  scanf("%d", &a);
  printf(">>>");
  scanf("%d", &b);
  printf(">>>");
  scanf("%d", &c);
  Triangle ans = { a, b, c };
  return ans;
}

Bool checkTriangle(Triangle t) {
  return (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) ? True : False;
}

void identTriangle(Triangle t) {
  int maxSide = t.a;
  int side1 = t.b, side2 = t.c;

  if (t.b > maxSide) {
      maxSide = t.b;
      side1 = t.a;
      side2 = t.c;
  }
  if (t.c > maxSide) {
      maxSide = t.c;
      side1 = t.a;
      side2 = t.b;
  }
  int katets = side1*side1 + side2*side2;
  int hipo = maxSide*maxSide;
  if (hipo == katets) {
    printf("\nПрямокутний");
  } else if (hipo > katets) {
    printf("\nГострий");
  } else {
    printf("\nТупий");
  }
}

char* num_to_str(int num) {
  char* ans = (char *)malloc(50);
  strcat(ans, nums_h[(int)(num/100)-1]);
  strcat(ans, " ");
  strcat(ans, nums_d[((num%100)/10)-1]);
  strcat(ans, " ");
  strcat(ans, nums[(num%10)-1]);
  strcat(ans, "\0");
  printf("%s", ans);
  free(ans);
}

int main() {
  printf("Умовний тернарний оператор (2 > 4): %s", 2 > 4 ? "True\n\n" : "False\n\n");

  Triangle t = newTriangle();
  while (checkTriangle(t) == False) {
    printf("Такий трикутник не може існувати! Спробуйте ще раз!\n");
    t = newTriangle();
  }

  identTriangle(t);

  int user;
  printf("\nУведіть тризначне число: ");
  scanf("%d", &user);
  num_to_str(user);
}