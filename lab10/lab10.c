#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int len(char str[]) {
    char* ptr = str;
    int cnt = 0;

    while (*ptr != '\0') {
        ptr++;
        cnt++;
    }
    return cnt;
}

int* toPoint(int x, int y) {
    int* ptr = (int*)malloc(2 * sizeof(int));
    ptr[0] = x; ptr[1] = y;
    return ptr;
}

float _add(float a, float b) {
    return a + b;
}

float _sub(float a, float b) {
    return a - b;
}

float _mul(float a, float b) {
    return a * b;
}

float _div(float a, float b) {
    return b ? a / b : NAN;
}

int main() {
    // str length with only stdio.h
    char str[] = "Lolis are the best";
    printf("str length: %d\n", len(str));

    // point to pointer
    int x, y;
    printf("input (x y): ");
    scanf("%d%d", &x, &y);
    int* ptr = toPoint(x, y);
    printf("your point: (%d, %d)\n", ptr[0], ptr[1]);
    printf("its address: %p\n", ptr);
    free(ptr);

    // solve expression
    printf("enter your expression (1.28+3.14): ");
    float a, b;
    char op;
    scanf("%f%c%f", &a, &op, &b);
    float (*ops[4])(float, float) = {_add, _sub, _mul, _div};
    printf("result: %f", ops[(op == '+') ? 0 : (op == '-') ? 1 : (op == '*') ? 2 : (op == '/') ? 3 : -1](a, b));

    
    return 0;
}
