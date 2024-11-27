#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char reversed_line[MAX_LINE_LENGTH];
    int line_count = 0, char_count = 0, total_chars = 0;
    long file_size;
    
    
    file = fopen("mfile.txt", "r");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        return 1;
    }


    printf("File contents:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        line_count++;
        total_chars += strlen(line) - 1; 
    }

    printf("Number of lines: %d\n", line_count);
    printf("Average number of characters per line: %.2f\n", (float)total_chars / line_count);
    
   
    fseek(file, 0, SEEK_SET);  

    FILE *reversed_file = fopen("xfile.txt", "w");
    if (reversed_file == NULL) {
        printf("Unable to open file for writing.\n");
        fclose(file);
        return 1;
    }

 
    fseek(file, 0, SEEK_END); 
    file_size = ftell(file); 

    for (long i = file_size - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        fgets(line, sizeof(line), file);

       
        int len = strlen(line) - 1; 
        int j;
        for (j = 0; j < len; j++) {
            reversed_line[j] = line[len - j - 1];
        }
        reversed_line[j] = '\0';

      
        fprintf(reversed_file, "%s\n", reversed_line);
    }

    fclose(file);
    fclose(reversed_file);
    printf("File reversed and saved to xfile.txt.\n");

    return 0;
}
