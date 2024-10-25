#include <stdio.h>
#include <math.h> // for NAN

// 2. функція для перевірки чи число просте
int task2(int a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

// 3. функція для обчислення суми чисел від A до 100
int task3(int a) {
    if (a > 100) return 0;
    return a + task3(a + 1);
}

// 4. функція для знаходження кореня рівняння методом половинного ділення
double task4(int N, int A, double l = -100, double r = 100) {
    if (N == 0) {
        printf("рівняння не має розв'язів.\n");
        return NAN;
    }
    double m;
    while ((r - l) >= 1e-5) {
        m = l + (r - l) / 2;
        if (N * m + A == 0) return m;
        if (N * m + A > 0) r = m;
        else l = m;
    }
    return m;
}

int main() {
    int a, N = 12, A = 17; // N - номер, A - вік
    
    // 1. Перевірка на простоту
    printf("Введіть число: ");
    scanf("%d", &a);
    if (task2(a))
        printf("%d є простим числом.\n", a);
    else
        printf("%d не є простим числом.\n", a);
    
    // 2. Рекурсивна сума
    printf("Сума чисел від %d до 100: %d\n", N, task3(N));

    // 3. Метод половинного ділення
    if (!isnan(task4(N, A)))
        printf("Розв'язок рівняння %d*x + %d = 0: x ≈ %.8f\n", N, A, result);

    return 0;
}
