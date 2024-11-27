#include <stdio.h>
#include <string.h>

#define PLAYER_COUNT 7

struct Player {
    char lastName[50];
    char firstName[50];
    int height;
    float weight;
    int age;
    char hairColor[20];
};


void sortPlayersByAge(struct Player players[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (players[j].age < players[j + 1].age) {
                struct Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Player players[PLAYER_COUNT];

    
    printf("Введіть дані про %d гравців:\n", PLAYER_COUNT);
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("Гравець %d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", players[i].lastName);
        printf("Ім'я: ");
        scanf("%s", players[i].firstName);
        printf("Зріст (см): ");
        scanf("%d", &players[i].height);
        printf("Маса (кг): ");
        scanf("%f", &players[i].weight);
        printf("Вік: ");
        scanf("%d", &players[i].age);
        printf("Колір волосся: ");
        scanf("%s", players[i].hairColor);
        printf("\n");
    }

    
    sortPlayersByAge(players, PLAYER_COUNT);

    
    printf("\nСписок гравців у порядку зменшення віку:\n");
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("%s %s | Вік: %d | Зріст: %d см | Маса: %.1f кг | Колір волосся: %s\n",
               players[i].lastName, players[i].firstName, players[i].age,
               players[i].height, players[i].weight, players[i].hairColor);
    }

    return 0;
}
