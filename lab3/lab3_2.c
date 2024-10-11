#include <stdio.h>
#include <string.h>

#define MAX 47 // Максимальна кількість записів
#define NAME_LEN 30
#define EMAIL_LEN 40
#define COLOR_LEN 20

typedef struct {
    int number;
    char surname[NAME_LEN];
    char initials[NAME_LEN];
    char email[EMAIL_LEN];
    char favoriteColor[COLOR_LEN];
} Person;

void printHeader() {
    printf("+----+-------------------------+-----------+-----------------------------+------------------+\n");
    printf("| No | Прізвище                | Ініціали  | Ел.пошта                    | Улюблений колір  |\n");
    printf("+----+-------------------------+-----------+-----------------------------+------------------+\n");
}

void printPerson(Person p) {
    printf("| %-2d | %-23s | %-9s | %-27s | %-16s |\n", p.number, p.surname, p.initials, p.email, p.favoriteColor);
}

int main() {
    Person people[MAX];
    int n;

    printf("Введіть кількість осіб (макс %d): ", MAX);
    scanf("%d", &n);
    getchar(); // Для зчитування символу нової строки після вводу кількості

    if (n > MAX) {
        printf("Кількість осіб перевищує дозволений максимум.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        people[i].number = i + 1;

        printf("Введіть прізвище особи %d: ", i + 1);
        fgets(people[i].surname, NAME_LEN, stdin);
        people[i].surname[strcspn(people[i].surname, "\n")] = 0; // Видаляємо символ нового рядка

        printf("Введіть ініціали особи %d: ", i + 1);
        fgets(people[i].initials, NAME_LEN, stdin);
        people[i].initials[strcspn(people[i].initials, "\n")] = 0;

        printf("Введіть ел.пошту особи %d: ", i + 1);
        fgets(people[i].email, EMAIL_LEN, stdin);
        people[i].email[strcspn(people[i].email, "\n")] = 0;

        printf("Введіть улюблений колір особи %d: ", i + 1);
        fgets(people[i].favoriteColor, COLOR_LEN, stdin);
        people[i].favoriteColor[strcspn(people[i].favoriteColor, "\n")] = 0;
    }

    // Виведення таблиці
    printHeader();
    for (int i = 0; i < n; i++) {
        printPerson(people[i]);
    }
    printf("+----+-------------------------+-----------+-----------------------------+------------------+\n");

    return 0;
}
