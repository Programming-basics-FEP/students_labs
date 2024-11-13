#include <stdio.h>

int string_length(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[] = "Hello, world!";
    printf("Length of the string: %d\n", string_length(str));
    return 0;
}

