#include <stdio.h>
#include <math.h> 

int main() {
    double a, b, c;  // Коефіцієнти квадратного рівняння
    double discriminant, root1, root2;  // Дискримінант та корені рівняння

    // Введення коефіцієнтів
    printf("Введіть коефіцієнти a, b і c для рівняння ax^2 + bx + c = 0:\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    // Обчислення дискримінанту
    discriminant = b * b - 4 * a * c;

    // Перевірка дискримінанту для визначення кількості коренів
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Рівняння має два дійсних корені: root1 = %.2lf і root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Рівняння має один дійсний корінь: root = %.2lf\n", root1);
    }
    else if (discriminant < 0){
        printf("Рівняння не має дійсних коренів");
    }
    return 0;
}