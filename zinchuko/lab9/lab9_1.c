#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PEOPLE 100  // максимальна кількість учасників
#define MAX_NAME_LEN 50 // максимальна довжина імені або прізвища

typedef struct {
    int number;
    char lastName[MAX_NAME_LEN];
    char firstName[MAX_NAME_LEN];
} Person;

// Функція порівняння для сортування в алфавітному порядку
int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return strcmp(personA->firstName, personB->firstName);
}

int main() {
    Person people[MAX_PEOPLE];
    int count = 0;
    char input[100];
    
    printf("Введіть список у форматі Номер-Прізвище-Ім’я (або 'end' для завершення):\n");
    
    // Пострічкове введення
    while (1) {
        printf("Введіть учасника %d: ", count + 1);
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "end\n") == 0) {
            break;
        }
        
        // Розбір рядка
        sscanf(input, "%d %s %s", &people[count].number, people[count].lastName, people[count].firstName);
        count++;
    }
    
    // 1) Підрахунок кількості відмінних імен та середньої довжини прізвищ
    int uniqueNamesCount = 0;
    int totalLastNameLength = 0;
    
    for (int i = 0; i < count; i++) {
        totalLastNameLength += strlen(people[i].lastName);
        
        // Перевірка унікальності імені
        int isUnique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(people[i].firstName, people[j].firstName) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            uniqueNamesCount++;
        }
    }
    
    double averageLastNameLength = (double)totalLastNameLength / count;
    
    printf("Кількість відмінних імен: %d\n", uniqueNamesCount);
    printf("Середня довжина прізвищ: %.2f\n", averageLastNameLength);
    
    // 2) Сортування та вивід у форматі Номер-Ім'я-Прізвище
    qsort(people, count, sizeof(Person), compare);
    
    printf("Список в алфавітному порядку:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %s\n", people[i].number, people[i].firstName, people[i].lastName);
    }
    
    return 0;
}
