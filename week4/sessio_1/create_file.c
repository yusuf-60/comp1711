#include <stdio.h>

int main () {
    char* filename = "data.txt";
    FILE *file = fopen (filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(file, "hello worldo!!\n");
    
    fclose(file);
    return 0;
}