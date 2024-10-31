#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[100]; // Масив для зберігання речення
    int vowel_count = 0; // Лічильник голосних
    int consonant_count = 0; // Лічильник приголосних

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Зчитування речення з введення

    // Перебір кожного символу в реченні
    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]); // Перетворення символу на малу букву

        // Перевірка, чи символ є літерою
        if (isalpha(ch)) {
            // Перевірка, чи є символ голосною
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel_count++;
            } else {
                consonant_count++;
            }
        }
    }

    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    return 0;
}
