#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "a"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    int number;
    int num_lines;
    int total = 0;
    float mean;//this is the mean
    //look at atoi
    
    printf("how many lines would you like to enter?: ");
    scanf("%d",&num_lines);

    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
        total+=number;
    }

    mean=total/num_lines;

    fprintf(file,"%f\n",mean);
    printf("the mean is %f",mean);
    fclose(file);
    return 0;
}