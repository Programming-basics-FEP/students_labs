#include <stdio.h>
// Функція для перетворення числа в двійковий формат
int b2(int x) {
  int r;
  if (x == 0)
    return 0;
  else {
    r = b2(x / 2);
    return r * 10 + (x % 2);
  }
}
int main() {
  char lin[] = "Лабораторна робота №3";
  printf(" %-10s\n", lin);
  printf("\nВирівнювання по правому краю:\n");
  {
    int d1 = 329492, d2 = 69, d3 = 321, d4 = 1;
    printf("%10d\n%10d\n%10d\n%10d\n", d1, d2, d3, d4);
  }
  printf("\nВирівнювання по лівому краю:\n");
  {
    int d1 = 234, d2 = 54324523, d3 = 43523, d4 = 19;
    printf("%-5d\n%-5d\n%-5d\n%-5d\n", d1, d2, d3, d4);
  }
  printf("\nВивід 0 в символах, яких бракує:\n");
  {
    int d1 = 5634;
    printf("%09d\n", d1);
  }
  printf("\nЗадана точність 5 символів:\n");
  {
    int d1 = 548;
    printf("%.5d\n", d1);
  }
  printf("\nЗадана ширина 5 символів:\n");
  {
    int d1 = 519958;
    printf("%.5d\n", d1);
  }
  printf("\nДані типу char:\n");
  {
    char line[] = "what";
    printf("%s\n", line);
  }
  printf("\nЧисло типу short int:\n");
  {
    short int d1 = 5434;
    printf("%hd\n", d1);
  }
  printf("\nЧисло типу long int:\n");
  {
    long int d1 = 198149815165488;
    printf("%ld\n", d1);
  }
  printf("\nЧисло типу long long int:\n");
  {
    long long int d1 = 4555555587449581656;
    printf("%lld\n", d1);
  }
  printf("\nЦіле беззнакове число:\n");
  {
    unsigned int d1 = 98765;
    printf("%u\n", d1);
  }
  {
    int x = 175;
    printf("\nЦіле число у десятковому форматі: %d\n", x);
    printf("\nЦіле число у двійковому форматі: %d\n",
           b2(x)); // Додати "b" вручну
    printf("\nЦіле число у вісімковому форматі: %o\n", x);
    printf("\nЦіле число у шістнадцятковому форматі: %X\n", x);
  }
  {
    float y = 2313.21312f;
    printf("\nДійсне число у формі з плаваючою комою: %f\n", y);
    printf("\nДійсне число в експоненційній формі : %e\n", y);
    printf("\nДійсне число в гнучкій формі : %g\n", y);
  }
  char sym = 'o';
  printf("\nВивести символ : %c\n", sym);
  char line2[] = "Живі бджоли гудуть"; // Уникати повторних назв змінних
  printf("\nВивести стрічку : %s\n", line2);
  char point[] = "Живі бджоли гудуть";
  printf("\nВивести вказівник : %p\n",
         (void *)point); // Вказівник треба приводити до void*
  return 0;
}
