
#include <stdio.h>

int main() {
    FILE *file;
    char line[256];
    int i;

    file = fopen("mfile.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    printf("Enter at least 10 lines of text:\n");
    for (i = 0; i < 10; i++) {
        printf("Line %d: ", i + 1);
        fgets(line, sizeof(line), stdin);  
        fprintf(file, "%s", line);          
    }

    fclose(file);
    printf("Lines successfully written to mfile.txt.\n");

    return 0;
}

