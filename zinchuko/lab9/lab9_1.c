#include <stdio.h>
#include <string.h>

void reverseWord(char* word) {
    int len = strlen(word);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
}

int main() {
    char sentence[256];
    printf("Введіть прислів'я або афоризм (мінімум 7 слів):\n");
    fgets(sentence, sizeof(sentence), stdin); 

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        reverseWord(word);
        printf("\n");
        word = strtok(NULL, " ");
    }

    return 0;
}

