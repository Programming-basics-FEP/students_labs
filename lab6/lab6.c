#include <stdio.h>
#include <ctype.h>

void task2() {
    char sentence[100];
    int vow = 0, cons = 0;

    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; ++i) {
        char c = tolower(sentence[i]);
        if ('a' <= c && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vow++;
            else
                cons++;
        }
    }

    printf("Голосних: %d\n", vow);
    printf("Приголосних: %d\n\n", cons);
}

void task3() {
    int sum = 0;

    int i = 1;
    while (i <= 100) {
        if (i != 12 && i != 33) { // я не знаю який я номер в журналі, тому використав 12
            sum += i;
        }
        i++;
    }

    printf("Сума перших 100 чисел, окрім 12 та 33: %d\n\n", sum);
}

void task4() {
    int N;
    float a, sum = 0, avg, mn, mx;

    do {
        printf("Введіть ціле число N (від 7 до 12): ");
        scanf("%d", &N);
    } while (N < 7 || N > 12);

    printf("Введіть %d дійсних чисел:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &a);
        sum += a;
        if (i == 0) {
            mn = mx = a;
        } else {
            if (a < mn) mn = a;
            if (a > mx) mx = a;
        }
    }

    avg = sum / N;

    printf("Сума: %.3f\n", sum);
    printf("Середнє арифметичне: %.3f\n", avg);
    printf("Мінімум: %.3f\n", mn);
    printf("Максимум: %.3f\n", mx);
}

int main() {

    // 2. підрахунок голосних і приголосних
    task2();        
    
    // 3.: підрахунок суми чисел з виключенням
    task3();        

    // 4. обчислення суми, середнього, мінімуму та максимуму
    task4();        

    return 0;
}
