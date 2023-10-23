#include "utils.h"

int main()
{
    char *filename = "squares.dat";
    FILE *file = open_file(filename, "w");

    unsigned long long number;

    printf("how many numbers do you want the square numebrs for from 1-n?: ");
    scanf("%llu",&number);

    for (unsigned long long i = 1; i < number; i++)
    {
        fprintf(file, "%llu\n", (i*i));
    }

    fclose(file);
    return 0;
}











