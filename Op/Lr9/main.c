#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool check_text(char* text) {
    int sz = strlen(text);
    int ctr = 0;
    bool in_word = false;

    for (int i = 0; i < sz; i++) {
        if (text[i] == ' ') {
            if (in_word) {
                ctr++;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }

    if (in_word) {
        ctr++;
    }

    return ctr >= 7;
}

void task_one() {
    char* text = (char*)malloc(256 * sizeof(char));

    printf("Уведіть прислів'я або афоризм, розділяючи кожне слово пробілом: ");
    scanf(" %[^\n]", text);

    while (!check_text(text)) {
        printf("У тексті менше 7 слів!\nСпробуй ще раз: ");
        scanf(" %[^\n]", text);
    }

    

    free(text);
}

int main() {
    task_one();
    return 0;
}
