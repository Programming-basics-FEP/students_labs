#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>

void reverseSentence ()
{
    char str[3000], *k = str;
    int word = 0;
    int begin = 0, end = 0, j;

    printf("\nВведіть прислів'я або афоризм англійською:\n"); 
    scanf("%[^\n]s", str);

    while (*k != '\0') { 
        if (*k == ' ') {
            word++; 
        }
        k++;
    }
    word++;


    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == ' ' || i == strlen(str)) {
            end = i - 1;
            for(j = end; j >= begin; --j)
                printf("%c", str[j]);
            printf("\n");
            begin = i + 1;
        }
    }
}

void swap(char *str1, char *str2) {
    char trash[50];
    strcpy(trash, str1);
    strcpy(str1, str2);
    strcpy(str2, trash);
}
void swapd(int *d1, int *d2) {
    int trash = *d1;
    *d1 = *d2;
    *d2 = trash;
}

void sigma() {
    int studCount;
    printf("\nВведіть кількість студентів:\n");
    scanf("%d", &studCount);

    // Перевірка мінімальної кількості студентів
    if (studCount < 10) {
        printf("Кількість має бути не менше 10\n");
        return;
    }

    int numm[studCount];
    char name[studCount][50];
    char surname[studCount][50];

    // Введення даних студентів
    printf("\nВведіть список групи (англійською) у форматі:\n");
    printf("номер прізвище ім'я\n");
    for (int a = 0; a < studCount; a++) {
        scanf("%d%s%s", &numm[a], surname[a], name[a]);
    }

    // Пошук унікальних імен
    char diferentNames[studCount][50];
    strcpy(diferentNames[0], name[0]);
    int massEnd = 1;  // Кількість різних імен
    for (int a = 1; a < studCount; a++) {
        int compareResult = 0;
        for (int b = 0; b < massEnd; b++) {
            if (strcmp(name[a], diferentNames[b]) == 0) {
                compareResult = 1;  // Якщо ім'я вже є в масиві
                break;
            }
        }
        if (compareResult == 0) {
            strcpy(diferentNames[massEnd], name[a]);  // Додаємо нове ім'я
            massEnd++;
        }
    }
    printf("\nКількість різних імен = %d\n", massEnd);

    // Обчислення середньої довжини прізвищ
    int summ = 0;
    for (int a = 0; a < studCount; a++) {
        summ += strlen(surname[a]);
    }
    int middle = summ / studCount;
    printf("Середня довжина прізвищ = %d\n", middle);

    for (int a = 0; a < studCount - 1; a++) {
        for (int b = 0; b < studCount - 1; b++) {
            if (strcmp(surname[b], surname[b + 1]) > 0) {
                swap(surname[b], surname[b + 1]); // Міняємо прізвища
                swap(name[b], name[b + 1]);       // Міняємо імена
                swapd(&numm[b], &numm[b + 1]);    // Міняємо номери
            }
        }
    }

    // Виведення відсортованих даних
    for (int a = 0; a < studCount; a++) {
        printf("%d %s %s\n", numm[a], name[a], surname[a]);
    }

    return;
}


void checkEmail() {
    char email[1000]; 
    
    printf("Введіть адресу електронної пошти:\n");
    if (scanf("%99s", email) != 1) {
        printf("Невірний формат вводу.\n");
        return;
    }

    if (isValidEmail(email)) {
        printf("Адреса електронної пошти правильна.\n");
    } else {
        printf("Адреса електронної пошти неправильна.\n");
    }
}

int isValidEmail(const char* email) {
    regex_t regex;
    const char* pattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}$";

    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        return 0;
    }
    
    if (regexec(&regex, email, 0, NULL, 0)) {
        regfree(&regex);
        return 0;
    }

    regfree(&regex);
    return 1;
}

int main() {
    reverseSentence();
    sigma();
    checkEmail();
    return 0;
}
