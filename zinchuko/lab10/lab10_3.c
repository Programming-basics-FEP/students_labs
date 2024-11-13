
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double (*operation)(double, double);

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { 
    if (b != 0) return a / b; 
    printf("Error: Division by zero\n");
    return 0; 
}

int main() {
    operation ops[4] = { add, subtract, multiply, divide };
    char input[100];
    double num1, num2;
    char operator;
    
    printf("Enter an expression (e.g., 1.28+3.14): ");
    fgets(input, sizeof(input), stdin);
    
    if (sscanf(input, "%lf %c %lf", &num1, &operator, &num2) != 3) {
        printf("Invalid input format\n");
        return 1;
    }

    double result;
    switch (operator) {
        case '+': result = ops[0](num1, num2); break;
        case '-': result = ops[1](num1, num2); break;
        case '*': result = ops[2](num1, num2); break;
        case '/': result = ops[3](num1, num2); break;
        default: 
            printf("Unknown operator\n");
            return 1;
    }

    printf("Result: %.2lf\n", result);
    return 0;
}
