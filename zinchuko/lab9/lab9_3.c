#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isValidEmail(char *email) {
  char *atPos = strchr(email, '@');
  char *dotPos = strrchr(email, '.');

  if (atPos == NULL || dotPos == NULL || atPos > dotPos) {
    return 0;
  }

  if (atPos == email || *(atPos + 1) == '\0') {
    return 0;
  }

  if (*(dotPos + 1) == '\0') {
    return 0;
  }

  for (char *p = email; *p; p++) {
    if (!isalnum(*p) && *p != '.' && *p != '@' && *p != '_') {
      return 0;
    }
  }

  return 1;
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

