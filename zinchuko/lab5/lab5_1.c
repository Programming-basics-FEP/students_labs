#include <stdio.h>

void printHundreds(int num) {
    switch (num) {
        case 1: printf("сто "); break;
        case 2: printf("двісті "); break;
        case 3: printf("триста "); break;
        case 4: printf("чотириста "); break;
        case 5: printf("п'ятсот "); break;
        case 6: printf("шістсот "); break;
        case 7: printf("сімсот "); break;
        case 8: printf("вісімсот "); break;
        case 9: printf("дев'ятсот "); break;
    }
}

void printTens(int num) {
    if (num >= 10 && num <= 19) {
        switch (num) {
            case 10: printf("десять"); break;
            case 11: printf("одинадцять"); break;
            case 12: printf("дванадцять"); break;
            case 13: printf("тринадцять"); break;
            case 14: printf("чотирнадцять"); break;
            case 15: printf("п'ятнадцять"); break;
            case 16: printf("шістнадцять"); break;
            case 17: printf("сімнадцять"); break;
            case 18: printf("вісімнадцять"); break;
            case 19: printf("дев'ятнадцять"); break;
        }
    } else {
        switch (num / 10) {
            case 2: printf("двадцять "); break;
            case 3: printf("тридцять "); break;
            case 4: printf("сорок "); break;
            case 5: printf("п'ятдесят "); break;
            case 6: printf("шістдесят "); break;
            case 7: printf("сімдесят "); break;
            case 8: printf("вісімдесят "); break;
            case 9: printf("дев'яносто "); break;
        }
    }
}

void printOnes(int num) {
    if (num >= 1 && num <= 9) {
        switch (num) {
            case 1: printf("один"); break;
            case 2: printf("два"); break;
            case 3: printf("три"); break;
            case 4: printf("чотири"); break;
            case 5: printf("п'ять"); break;
            case 6: printf("шість"); break;
            case 7: printf("сім"); break;
            case 8: printf("вісім"); break;
            case 9: printf("дев'ять"); break;
        }
    }
}

int main() {
    int num;
    printf("Введіть тризначне число: ");
    scanf("%d", &num);

    if (num < 100 || num > 999) {
        printf("Будь ласка, введіть тризначне число.\n");
        return 0;
    }

    printHundreds(num / 100);
    int lastTwoDigits = num % 100;

    if (lastTwoDigits >= 10 && lastTwoDigits <= 19) {
        printTens(lastTwoDigits);
    } else {
        printTens(lastTwoDigits);
        printOnes(lastTwoDigits % 10);
    }

    printf("\n");

    return 0;
}
