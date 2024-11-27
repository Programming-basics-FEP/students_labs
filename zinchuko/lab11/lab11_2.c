#include <stdio.h>
#include <string.h>

#define LAPTOP_COUNT 7

struct Laptop {
    char manufacturer[50];
    float displaySize;
    char resolution[20];
    char processorType[50];
    int ramSize;
    char storageType[20];
    int storageCapacity;
    char gpuType[50];
    int batteryCapacity;
    float price;
};

void printLaptop(struct Laptop laptop) {
    printf("Виробник: %s\n", laptop.manufacturer);
    printf("Розмір дисплея: %.1f дюймів\n", laptop.displaySize);
    printf("Роздільна здатність дисплея: %s\n", laptop.resolution);
    printf("Тип процесора: %s\n", laptop.processorType);
    printf("Розмір оперативної пам'яті: %d ГБ\n", laptop.ramSize);
    printf("Тип накопичувача: %s\n", laptop.storageType);
    printf("Обсяг диска: %d ГБ\n", laptop.storageCapacity);
    printf("Тип відеокарти: %s\n", laptop.gpuType);
    printf("Ємність акумулятора: %d мАг\n", laptop.batteryCapacity);
    printf("Ціна: %.2f грн\n", laptop.price);
}

int main() {
    struct Laptop laptops[LAPTOP_COUNT];

   
    printf("Введіть дані про %d ноутбуків:\n", LAPTOP_COUNT);
    for (int i = 0; i < LAPTOP_COUNT; i++) {
        printf("Ноутбук %d:\n", i + 1);
        printf("Виробник: ");
        scanf("%s", laptops[i].manufacturer);
        printf("Розмір дисплея (в дюймах): ");
        scanf("%f", &laptops[i].displaySize);
        printf("Роздільна здатність дисплея: ");
        scanf("%s", laptops[i].resolution);
        printf("Тип процесора: ");
        scanf("%s", laptops[i].processorType);
        printf("Розмір оперативної пам'яті (ГБ): ");
        scanf("%d", &laptops[i].ramSize);
        printf("Тип накопичувача: ");
        scanf("%s", laptops[i].storageType);
        printf("Обсяг диска (ГБ): ");
        scanf("%d", &laptops[i].storageCapacity);
        printf("Тип відеокарти: ");
        scanf("%s", laptops[i].gpuType);
        printf("Ємність акумулятора (мАг): ");
        scanf("%d", &laptops[i].batteryCapacity);
        printf("Ціна (грн): ");
        scanf("%f", &laptops[i].price);
        printf("\n");
    }

   
    printf("\nДані про всі ноутбуки:\n");
    for (int i = 0; i < LAPTOP_COUNT; i++) {
        printf("\nНоутбук %d:\n", i + 1);
        printLaptop(laptops[i]);
    }

   
    int choice;
    printf("\nОберіть номер ноутбука (1-%d), щоб переглянути його характеристики: ", LAPTOP_COUNT);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= LAPTOP_COUNT) {
        printf("\nХарактеристики ноутбука %d:\n", choice);
        printLaptop(laptops[choice - 1]);
    } else {
        printf("Невірний вибір.\n");
    }

    return 0;
}
