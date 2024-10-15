#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return (n == 2);

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int f(int x) {
    return 3 * x - 19;
}

double bisection_method(double from, double to) {
    double mid;
    while ((to - from) > 1e-6) {
        mid = (from + to) / 2;
        if (f(mid) == 0) return mid;
        if (f(mid) * f(from) < 0) {
            to = mid;
        } else {
            from = mid;
        }
    }
    return (from + to) / 2;
}

int main() {
    printf("---| З А В Д А Н Н Я  1 |---\n");
    printf("%s", (is_prime(953) ? "True\n" : "False\n"));
    printf("---| З А В Д А Н Н Я  2 |---\n");
    int root = bisection_method(-100, 100);
    if (root != -1) {
        printf("Корень: %f\n", (float)root);
    }
}
