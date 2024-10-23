#include <stdio.h>

int main(void) {
  // Створення змінних
  char surname[30];
  char name[30];
  char email[30];
  char phone[15];
  char favouritecolor[30];

  // Ввід даних
  printf("Enter your name: \t");
  scanf("%30s", name);
  printf("Enter your surname: \t");
  scanf("%30s", surname);
  printf("Enter your email: \t");
  scanf("%30s", email);
  printf("Enter your phone: \t");
  scanf("%15s", phone);
  printf("Enter your favourite color: \t");
  scanf("%30s", favouritecolor);
  printf("\n%-20s %-20s %-30s %-20s %-25s\n", "Name", "Surname", "Email",
         "Phone", "Favourite color");
  printf("---------------------------------------------------------------------"
         "--------------------------------\n");

  printf("%-20s %-20s %-30s %-20s %-25s\n", name, surname, email, phone,
         favouritecolor);

  return 0;
}
