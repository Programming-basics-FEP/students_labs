#include <stdio.h>
#include <string.h>

typedef struct {
    char surname[47];
    char name[47];
    int age;
    float height;
    float weight;
    char hairColor[47];
} Player;

typedef struct {
    char manufacturer[47];
    float screenSize;
    char resolution[47];
    char processorType[47];
    int ramSize;
    char storageType[47];
    int diskSize;
    char graphicsCard[47];
    int batteryCapacity;
    float price;
} Laptop;

void sort(Player players[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mxj = i;
        for (int j = i + 1; j < n; j++) {
            if (players[j].age > players[mxj].age) {
                mxj = j;
            }
        }
        
        Player temp = players[mxj];
        players[mxj] = players[i];
        players[i] = temp;
    }
}

void printLaptop(Laptop laptop) {
    printf("\nManufacturer: %s\n", laptop.manufacturer);
    printf("Screen Size: %.2f inches\n", laptop.screenSize);
    printf("Resolution: %s\n", laptop.resolution);
    printf("Processor Type: %s\n", laptop.processorType);
    printf("RAM Size: %d GB\n", laptop.ramSize);
    printf("Storage Type: %s\n", laptop.storageType);
    printf("Disk Size: %d GB\n", laptop.diskSize);
    printf("Graphics Card: %s\n", laptop.graphicsCard);
    printf("Battery Capacity: %d mAh\n", laptop.batteryCapacity);
    printf("Price: %.2f\n", laptop.price);
}

void chooseLaptop(Laptop laptops[], int n) {
    int choice;
    printf("\nPlease choose a laptop by id: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < n) {
        printLaptop(laptops[choice]);
    } else {
        printf("invalid ♿\n");
    }
}

int main()
{
    Player players[47];
    int n;
    printf("Enter the number of players: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for player %d:\n", i + 1);
        printf("Surname: ");
        scanf("%s", players[i].surname);
        printf("Name: ");
        scanf("%s", players[i].name);
        printf("Age: ");
        scanf("%d", &players[i].age);
        printf("Height (cm): ");
        scanf("%f", &players[i].height);
        printf("Weight (kg): ");
        scanf("%f", &players[i].weight);
        printf("Hair Color: ");
        scanf("%s", players[i].hairColor);
    }

    sort(players, n);
    printf("\nSorted list of players by age:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s %s, Age: %d, Height: %.2f cm, Weight: %.2f kg, Hair Color: %s\n",
               i + 1, players[i].surname, players[i].name, players[i].age, players[i].height, players[i].weight, players[i].hairColor);
    }

    // 2
    int m;
    Laptop laptops[47];
    printf("\nEnter the number of laptops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("\nEnter details for laptop %d:\n", i + 1);
        printf("Manufacturer: ");
        getchar();
        fgets(laptops[i].manufacturer, sizeof(laptops[i].manufacturer), stdin);
        laptops[i].manufacturer[strcspn(laptops[i].manufacturer, "\n")] = 0;

        printf("Screen Size (inches): ");
        scanf("%f", &laptops[i].screenSize);

        printf("Resolution: ");
        scanf("%s", laptops[i].resolution);

        printf("Processor Type: ");
        getchar();
        fgets(laptops[i].processorType, sizeof(laptops[i].processorType), stdin);
        laptops[i].processorType[strcspn(laptops[i].processorType, "\n")] = 0;

        printf("RAM Size (GB): ");
        scanf("%d", &laptops[i].ramSize);

        printf("Storage Type: ");
        scanf("%s", laptops[i].storageType);

        printf("Disk Size (GB): ");
        scanf("%d", &laptops[i].diskSize);

        printf("Graphics Card: ");
        getchar();
        fgets(laptops[i].graphicsCard, sizeof(laptops[i].graphicsCard), stdin);
        laptops[i].graphicsCard[strcspn(laptops[i].graphicsCard, "\n")] = 0;

        printf("Battery Capacity (mAh): ");
        scanf("%d", &laptops[i].batteryCapacity);

        printf("Price: ");
        scanf("%f", &laptops[i].price);
    }

    for (int i = 0; i < m; i++) {
        printf("\nId: %d", i);
        printLaptop(laptops[i]);
    }

    chooseLaptop(laptops, m);

    return 0;
}
