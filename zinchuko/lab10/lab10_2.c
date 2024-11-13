#include <stdio.h>
#include <stdlib.h>

int* toPoint(int x, int y) {
    int *point = (int*)malloc(2 * sizeof(int)); // Виділення пам'яті для двох цілих чисел
    if (point == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    point[0] = x; // Збереження координати x
    point[1] = y; // Збереження координати y
    return point;
}

int main() {
    int *point = toPoint(5, 10);
    if (point != NULL) {
        printf("Point coordinates: (%d, %d)\n", point[0], point[1]);
        printf("Pointer address: %p\n", (void*)point);
        free(point); // Звільнення пам'яті
    }
    return 0;
}

