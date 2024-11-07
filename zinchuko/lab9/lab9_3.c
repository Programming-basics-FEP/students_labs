#include <stdio.h>
#include <regex.h>

int isValidEmail(const char *email) {
    regex_t regex;
    int reti;

    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex); 

    if (!reti) {
        return 1;
    } else {
        return 0;  
    }
}

int main() {
    char email[100];
    printf("Введіть адресу електронної пошти: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Адреса електронної пошти коректна.\n");
    } else {
        printf("Адреса електронної пошти некоректна.\n");
    }

    return 0;
}
