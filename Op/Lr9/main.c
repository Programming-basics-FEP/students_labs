#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <stdbool.h>


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

User cmpuser(char* input) {
    User user;
    user.phone_number = (char*)malloc(20 * sizeof(char));
    user.name = (char*)malloc(50 * sizeof(char));
    user.surname = (char*)malloc(50 * sizeof(char));

    sscanf(input, "%19s %49s %49s", user.phone_number, user.surname, user.name);

    return user;
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

int mln_name(User* users) {
    int ctr = 0;
    for(int i = 0; i < 10; i++) {
        ctr += strlen(users[i].name);
    }
    return ctr/10;
}

bool is_ident(User* users, User user) {
    for(int i = 0; i<10; i++) {
        if (strcmp(users[i].name, user.name) == 0) return false;
    }
    return true;
}

int dif_names_ct(User* users) {
    int ident_ct = 0;
    User* ident_users = (User*)malloc(10*sizeof(User));
    for (int i = 0; i < 10; i++) {
        ident_users[i].phone_number = (char*)malloc(20 * sizeof(char));
        ident_users[i].name = (char*)malloc(50 * sizeof(char));
        ident_users[i].surname = (char*)malloc(50 * sizeof(char));
    }
    for(int i = 0; i<10; i++) {
        if(is_ident(ident_users, users[i])) {
            ident_users[ident_ct++] = users[i];
        }
    }
    free(ident_users);
    return ident_ct;
}

void swap(User* f, User* s) {
    char* phone_number = s->phone_number;
    char* name = s->name;
    char* surname = s->surname;

    s->phone_number = f->phone_number;
    s->name = f->name;
    s->surname = f->surname;

    f->phone_number = phone_number;
    f->name = name;
    f->surname = surname;
}

void sort_users(User* users) {
    for(int i = 0; i<10; i++) {
        for(int j = i+1; j<10; j++) {
           if (strcmp(users[i].name, users[j].name) > 0) {
                swap(&users[i], &users[j]);
            }
        }
    }
}

void task_two(User* users) {
    int dif_names = dif_names_ct(users);
    int mid_ln_names = mln_name(users);
    User* new_users = users;
    sort_users(new_users);
    printf("Кількість відмнних імен: %d\n", dif_names);
    printf("Середня довжина імен: %d\n", mid_ln_names);
    printf("Відсортований масив:\n");
    for(int i = 0; i<10; i++) {
        printf("\t(%d) %s - %s - %s\n", i, new_users[i].phone_number, new_users[i].name, new_users[i].surname);
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
    char* w_input = input("Завадання 1 - Уведіть текст");
    task_one(w_input);

    /// T A S K   T W O
    printf("(Завдання 2 - Уведіть тексту форматі: Номер Прізвище Ім'я)\n");
    User* u_input = (User*)malloc(15*sizeof(User));
    for(int i = 0; i<10; i++) {
        char* inp = (char*)malloc(100*sizeof(char));
        printf("\t(%d) ", i+1);
        fgets(inp, 100, stdin);
        u_input[i] = cmpuser(inp);
    }
    task_two(u_input);

    /// T A S K   T H R E E
    char* e_input = input("Завдання 3 - Уведіть електронну пошту");
    task_three(e_input);

    free(w_input);
    for (int i = 0; i < 10; i++) {
        free(u_input[i].phone_number);
        free(u_input[i].name);
        free(u_input[i].surname);
    }
    free(u_input);
    free(e_input);

    return 0;
}