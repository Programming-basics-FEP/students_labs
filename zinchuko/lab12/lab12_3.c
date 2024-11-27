#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *source_file, *dest_file;
    char source_filename[100], dest_filename[100];
    char buffer[1024];
    size_t bytes_read;

   
    printf("Enter the name of the source file to copy: ");
    scanf("%s", source_filename);

   
    if (strstr(source_filename, ".pdf") == NULL && strstr(source_filename, ".jpg") == NULL) {
        printf("Invalid file type. Only .pdf or .jpg files can be copied.\n");
        return 1;
    }


    source_file = fopen(source_filename, "rb");
    if (source_file == NULL) {
        printf("Unable to open source file for reading.\n");
        return 1;
    }

    
    snprintf(dest_filename, sizeof(dest_filename), "copy_of_%s", source_filename);

    
    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        printf("Unable to open destination file for writing.\n");
        fclose(source_file);
        return 1;
    }

   
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    printf("File copied successfully to %s.\n", dest_filename);

    fclose(source_file);
    fclose(dest_file);

    return 0;
}
