#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

typedef enum {
    Hol,
    PrHol
} Tokens;

wchar_t hol_chars[] = { L'а', L'і', L'е', L'о', L'у', L'и', L'А', L'І', L'Е', L'О', L'У', L'И' };

int is_hol(wchar_t a) {
    int num_chars = sizeof(hol_chars) / sizeof(hol_chars[0]);
    for (int i = 0; i < num_chars; i++) {
        if (a == hol_chars[i]) {
            return 1;
        }
    }
    return 0;
}

void parse_str(wchar_t* user, Tokens* ans, int* count) {
    int len = wcslen(user);
    for (int i = 0; i < len; i++) {
        if (user[i] == L' ') {
            i--;
            continue;
        }
        ans[i] = is_hol(user[i]) ? Hol : PrHol;
    }
    *count = len;
}

int task_two() {
    int i = 1;
    int ans_t2 = 0;
    while (i != 101) {
      if (i == 33 || i == 2) {
        i += 1;
        continue;
      }
      ans_t2 += i;
      i += 1;
    }
    return ans_t2;
}

void task_three() {
    int user[7];
    for (int i = 0; i < 7; i++) {
        wprintf(L"Уведіть число від 7 до 12 (%d/7):", i + 1);
        wscanf(L"%d", &user[i]);
        if(user[i]>12 || user[i]<7) {
          wprintf(L"Число повинно бути у діапазоні від 7 до 12!\n");
          i-=1;
        }
    }

    int sum = 0;
    int mid, min = user[0], max = user[0];
    for (int i = 0; i < 7; i++) {
        sum += user[i];
        if (user[i] < min) min = user[i];
        if (user[i] > max) max = user[i];
    }
    mid = sum / 7;
    wprintf(L"Сума: %d\n", sum);
    wprintf(L"Середнє арифметичне: %d\n", mid);
    wprintf(L"Мінімальне: %d\n", min);
    wprintf(L"Максимальне: %d\n", max);
}


int main() {
    setlocale(LC_ALL, "");
    wchar_t user[100];
    wprintf(L"Введите строку: ");
    wscanf(L"%ls", user);

    Tokens ans[100];
    int count = 0, hol_c = 0, prhol_c = 0;

    parse_str(user, ans, &count);

    printf("--- З А В Д А Н Н Я   1 ---");
    for (int i = 0; i < count; i++) {
      if(ans[i] == Hol) hol_c+=1;
      if(ans[i] == PrHol) prhol_c+=1;
        wprintf(L"Токен %lc: %s\n", user[i], (ans[i] == Hol ? "Голосна" : "Приголосна"));
    }
    wprintf(L"Кількість голосних: %d\nКількість приголосних: %d", hol_c, prhol_c);

    wprintf(L"\n\n--- З А В Д А Н Н Я   2 ---\n");
    wprintf(L"Сума 100 перших чисел окрім 33 та 2: %d", task_two());

    wprintf(L"\n\n--- З А В Д А Н Н Я   3 ---\n");
    task_three();
    return 0;
}
