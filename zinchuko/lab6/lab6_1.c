#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int vowels = 0, consonants = 0, i = 0;

    printf("Введіть довільне речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    while (sentence[i] != '\0') {
        char ch = tolower(sentence[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
                vowels++;
            } else {
                consonants++;
            }
        }
        i++;
    }

    printf("Кількість голосних букв: %d\n", vowels);
    printf("Кількість приголосних букв: %d\n", consonants);

    return 0;
}
