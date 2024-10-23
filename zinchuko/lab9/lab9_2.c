#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 20
#define MAX_NAME_LEN 50

typedef struct {
    int number;
    char surname[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
} Person;

void sortPeople(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(people[i].name, people[j].name) > 0 || 
                (strcmp(people[i].name, people[j].name) == 0 && strcmp(people[i].surname, people[j].surname) > 0)) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int countUniqueNames(Person people[], int count) {
    int uniqueNames = 1;  
    for (int i = 1; i < count; i++) {
        if (strcmp(people[i].name, people[i - 1].name) != 0) {
            uniqueNames++;
        }
    }
    return uniqueNames;
}

float averageSurnameLength(Person people[], int count) {
    int totalLength = 0;
    for (int i = 0; i < count; i++) {
        totalLength += strlen(people[i].surname);
    }
    return (float)totalLength / count;
}

int main() {
    int count;
    printf("Введіть кількість учасників (10+): ");
    scanf("%d", &count);
    getchar();  

    Person people[MAX_PEOPLE];
    for (int i = 0; i < count; i++) {
        printf("Введіть дані у форматі Номер Прізвище Ім'я: ");
        scanf("%d %s %s", &people[i].number, people[i].surname, people[i].name);
    }
    
    sortPeople(people, count);
    printf("\nСписок в алфавітному порядку (Номер Ім'я Прізвище):\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %s\n", people[i].number, people[i].name, people[i].surname);
    }

    int uniqueNames = countUniqueNames(people, count);
    printf("\nКількість різних імен: %d\n", uniqueNames);


    float avgSurnameLength = averageSurnameLength(people, count);
    printf("Середня довжина прізвищ: %.2f\n", avgSurnameLength);

    return 0;
}

