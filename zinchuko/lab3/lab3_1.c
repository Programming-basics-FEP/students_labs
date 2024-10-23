#include <stdio.h>

int main(void) {

  int number = printf("Введіть число 1: ");
  scanf("%d", &number);
  void *zxc = &number;

  printf("десяткове = %d\n", number);
  printf("двійкове = %b\n", number);
  printf("шістнадцяткове = %x\n", number);
  printf("Biciмкове = %o\n", number);

  float floatn = printf("Введіть число 2: ");
  scanf("%f", &floatn);
  
  printf("плаваюча = %f\n", floatn);
  printf("експонційна = %e\n", floatn);
  printf("гнучка = %g\n", floatn);
  
  char letter = printf("Введіть букву: ");
  scanf("%c", &letter);
  char strin[] = "Hello World";

  printf("символ = %c\n", letter);
  printf("стрічка = %s\n", strin);
  printf("вказiвник = %p\n", zxc);
  
  return 0;
}