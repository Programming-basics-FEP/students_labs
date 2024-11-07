#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n < 1) return false;
    if (n % 2 == 0) return (n == 2);

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int req_sum(int ctr) {
    if (ctr != 100) {
        return req_sum(ctr+1) + ctr;
    } else {
        return 100;
    }
}

double f(double x) {
    double N = 0;
    double A = 19;
    return (N==0) ? NAN : N * x + A;
}

double bisection_method(double from, double to) {
    if (isnan(f(52))) return NAN;
    double mid;
    while ((to - from) > 1e-6) {
        mid = (from + to) / 2;
        if (f(mid) == 0) return mid;
        if (f(mid) * f(from) < 0) to = mid;
        else from = mid;
    }
    return mid;
}

int main() {
    int user;
    printf("---| З А В Д А Н Н Я  1 |---\n");
    printf("Уведіть число щоб перевірити чи є воно простим: ");
    scanf("%d", &user);
    printf("Число %s ", (is_prime(user) ? "просте\n" : "не просте\n"));
    printf("---| З А В Д А Н Н Я  2 |---\n");
    printf("Рекурсивна сума від 10 до 100: %d\n", req_sum(10));
    printf("---| З А В Д А Н Н Я  3 |---\n");
    double root = bisection_method(-100, 100);
    if (!isnan(root)) printf("Корінь: %f\n", root);
    else printf("Немає коренів!!!!!!");
}