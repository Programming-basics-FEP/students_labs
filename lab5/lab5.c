#include <stdio.h>
#include <math.h>
#include <string.h>

// 2: Порівняння двох чисел
void comp_num(double a, double b) {
    printf((a>b) ? "a > b\n" : "a <= b\n");
}

// 3: Визначення типу трикутника
void tri_type(double a, double b, double c) {
    if (a+b<=c || a+c<=b || b+c<=a)
    {
        printf("Не трикутник\n");
        return;
    }
        
    char s_type[47];
    if (a==b && b==c) strcpy(s_type, "Рівносторонній");
    else if (a==b || b==c || a==c) strcpy(s_type, "Рівнобедрений");
    else strcpy(s_type, "Різносторонній");

    double sq[3] = {a*a, b*b, c*c};
    if (sq[0]>sq[1]) { double temp = sq[0]; sq[0] = sq[1]; sq[1] = temp; }
    if (sq[1]>sq[2]) { double temp = sq[1]; sq[1] = sq[2]; sq[2] = temp; }
    if (sq[0]>sq[1]) { double temp = sq[0]; sq[0] = sq[1]; sq[1] = temp; }

    char a_type[47];
    if (sq[0]+sq[1]==sq[2]) 
        strcpy(a_type, "прямокутний");
    else if 
        (sq[0]+sq[1]>sq[2]) strcpy(a_type, "гострокутний");
    else 
        strcpy(a_type, "тупокутний");

    printf("Трикутник %s і %s\n", s_type, a_type);
}

// 4: Перетворення числа на текст
void num_to_words(int n, char* res) {
    char* ones[] = {"", "один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};
    char* teens[] = {"десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев'ятнадцять"};
    char* tens[] = {"", "", "двадцять", "тридцять", "сорок", "п'ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев'яносто"};
    char* hundreds[] = {"", "Сто", "Двісті", "Триста", "Чотириста", "П'ятсот", "Шістсот", "Сімсот", "Вісімсот", "Дев'ятсот"};

    int h = n/100, r = n%100, t = r/10, o = r%10;

    if (n>100) sprintf(res, "%s ", hundreds[h]); 
    if (r==0) return;
    if (r<10) sprintf(res + strlen(res), "%s", ones[o]);
    else if (r<20) sprintf(res + strlen(res), "%s", teens[r-10]);
    else sprintf(res + strlen(res), "%s %s", tens[t], ones[o]);
}

int main() {
    // 2: Порівняння чисел
    double a, b;
    printf("Завдання 2: введіть два числа: ");
    scanf("%lf %lf", &a, &b);
    comp_num(a, b);

    // 3: Визначення типу трикутника
    double x, y, z;
    printf("Завдання 3: введіть сторони трикутника: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    tri_type(x, y, z);

    // 4: Перетворення тризначного числа на текст
    int n;
    char res[74];
    printf("Завдання 4: введіть тризначне число: ");
    scanf("%d", &n);
    num_to_words(n, res);
    printf("%s\n", res);

    return 0;
}
