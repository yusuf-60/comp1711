#include <stdio.h>
#include <stdlib.h>

int main() {
float mean1;

    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    //buffer size is the length of line whixh we will read in(100 is standard)
    int buffer_size = 1000;
    //a string which will hold each line as its read in(same size as buffer)
    char line_buffer[buffer_size];

    //while there is still data in the file then:
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        mean1=atoi(line_buffer); // to make it print as a float
        printf("%f\n",mean1); //always reads in as a string so we turn it into a number and then print as number 
    }

    fclose(file);
    return 0;
}