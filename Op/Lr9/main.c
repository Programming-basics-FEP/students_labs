#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>


typedef struct {
    char* phone_number;
    char* name;
    char* surname;
} User;

char* input(char* str) {
    char* inp = (char*)malloc(150*sizeof(char));
    printf("(%s)$ ", str);
    fgets(inp, 150, stdin);
    inp[strlen(inp)] = '\n';
    return inp;
}

char* rstr(char* str) {
    int ln = strlen(str);
    char* ans = (char*)malloc((ln + 1) * sizeof(char));
    for (int i = ln-1; i>=0; i--)
    { ans[ln-i-1] = str[i]; }
    return ans;
}

void showstr(char* str) {
    printf("%s\n", str);
}

User cmpuser(char* user) {
    User result;
    char* token;
    int start = 0;

    token = strtok(user, " ");
    if (token != NULL) {
        result.phone_number = token;
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        result.name = token;
    }

    token = strtok(NULL, " ");
    if (token != NULL) {
        result.surname = token;
    }

    return result;
}

void task_one(char* str) {
    int start = 0;
    int ln = strlen(str);
    for (int i = 0; i <= ln; i++) {
        if (isspace(str[i])) {
            if (i > start) {
                char* tmp = (char*)malloc((i - start + 1) * sizeof(char));
                strncpy(tmp, str + start, i - start);
                showstr(rstr(tmp));
                free(tmp);
            }
            start = i + 1;
        }
    }
}

void task_two(User* user) {
    for(int i = 0; i<10; i++) {
        
    }
}

void task_three(char* mail) {
    mail[strcspn(mail, "\n")] = '\0';
    const char* pattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}$";
    const char* string = mail;

    regex_t regex;
    int result;

    result = regcomp(&regex, pattern, REG_EXTENDED);
    result = regexec(&regex, string, 0, NULL, 0);
    if (result == 0) {
        printf("Це правильно введеня електронна пошта\n");
    } else if (result == REG_NOMATCH) {
        printf("Це неправильно введена електронна пошта\n");
    }

    regfree(&regex);
}

int main() {
    /// T A S K   O N E
    char* w_input = input("Завадання 1");
    task_one(w_input);
    free(w_input);

    /// T A S K   T W O
    printf("(Завдання 2)\n");
    User* u_input = (User*)malloc(15*sizeof(User));
    for(int i = 0; i<10; i++) {
        char* inp = (char*)malloc(100*sizeof(char));
        printf("\t(%d) ", i+1);
        fgets(inp, 100, stdin);
        u_input[i] = cmpuser(inp);
    }
    task_two(u_input);
    free(u_input);

    /// T A S K   T H R E E
    char* e_input = input("Завдання 3");
    task_three(e_input);
    free(e_input);

    return 0;
}