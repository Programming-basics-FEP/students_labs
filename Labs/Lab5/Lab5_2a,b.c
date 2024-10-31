#include <stdio.h>

int main(void) {
  #include <stdio.h>
  #include <math.h> // Для використання функції pow

      // Змінні для сторін трикутника з типом float
      float side1, side2, side3;

      // Введення довжин сторін
      printf("Введіть довжини трьох сторін трикутника (через пробіл): ");
      scanf("%f %f %f", &side1, &side2, &side3);

      // Перевірка чи сторони можуть утворювати трикутник
      if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
          // Визначення типу трикутника за сторонами
          if (side1 == side2 && side2 == side3) {
              printf("Трикутник є рівностороннім.\n");
          } else if (side1 == side2 || side1 == side3 || side2 == side3) {
              printf("Трикутник є рівнобедреним.\n");
          } else {
              printf("Трикутник є різностороннім.\n");
          }

          // Знаходження найбільшої сторони
          float maxSide = side1;
          float other1 = side2, other2 = side3;
          if (side2 > maxSide) {
              maxSide = side2;
              other1 = side1;
              other2 = side3;
          }
          if (side3 > maxSide) {
              maxSide = side3;
              other1 = side1;
              other2 = side2;
          }

          // Перевірка типу трикутника за кутами
          float maxSideSq = pow(maxSide, 2);
          float sumOtherSq = pow(other1, 2) + pow(other2, 2);

          if (fabs(maxSideSq - sumOtherSq) < 1e-6) {
              printf("Трикутник є прямокутним.\n");
          } else if (maxSideSq < sumOtherSq) {
              printf("Трикутник є гострокутним.\n");
          } else {
              printf("Трикутник є тупокутним.\n");
          }

      } else {
          // Якщо сторони не утворюють трикутник
          printf("Ці сторони не можуть утворювати трикутник.\n");
      }

      return 0;
  
 
}