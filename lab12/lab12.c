#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

// Write input to mfile
void task1() {
    FILE *file = fopen("mfile.txt", "w");
    if (file == NULL) return;

    char buffer[BUF_SIZE];
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(buffer, BUF_SIZE, stdin);
        fprintf(file, "%s", buffer);
    }

    printf("All strings have been written to 'mfile.txt'\n");
    fclose(file);
}

// Write reversed to xfile
void task2() {
    FILE *file = fopen("mfile.txt", "r");
    if (!file) return;

    char strings[1488][BUF_SIZE];
    int n = 0;
    while (n < 1488 && fgets(strings[n], BUF_SIZE, file)) {
        strings[n][strcspn(strings[n], "\n")] = '\0';
        n++;
    }
    fclose(file);

    for (int j = 0; j < n; j++) 
        printf("%s\n", strings[j]);

    printf("Number of lines: %d\n", n);

    int sum = 0;
    for (int j = 0; j < n; j++) 
        sum += strlen(strings[j]);

    printf("Average number of characters per line: %d\n", n > 0 ? sum / n : 0);

    file = fopen("xfile.txt", "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        int len = strlen(strings[i]);
        char tmp[BUF_SIZE];
        for (int j = 0; j < len; j++) tmp[j] = strings[i][len - j - 1];
        tmp[len] = '\0';
        fprintf(file, "%s\n", tmp);
    }

    printf("'xfile.txt' has been created with reversed strings.\n");
    fclose(file);
}

// Copy image
void task3() {
    FILE *src, *dest;

    src = fopen("photo.png", "rb");
    if (src == NULL) return;

    dest = fopen("newphoto.png", "wb");
    if (dest == NULL) return;

    char buffer[BUF_SIZE];
    size_t bytes_in, bytes_out;

    while ((bytes_in = fread(buffer, 1, BUF_SIZE, src)) > 0) {
        bytes_out = fwrite(buffer, 1, bytes_in, dest);
        if (bytes_out != bytes_in) return;
    }

    printf("File copied successfully.");
    fclose(dest);
    fclose(src);
}

int main() {
    void (*tasks[])() = { task1, task2, task3 };
    int t;
    printf("Enter the task number to run: ");
    if (scanf("%d", &t) != 1 || t < 1 || t > 3) {
        printf("Invalid ♿\n");
        return 1;
    }
    tasks[t-1]();
}
