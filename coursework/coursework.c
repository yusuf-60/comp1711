#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FITNESS_DATA Fitness[150];
    int buffer = 250;
    char line[buffer];
    int counter = 0;

    // opening the file, so that we can read into it
    FILE *file = fopen("FitnessData_2023.csv" , "r");

    //creating temporary storage for the data
    char date[11];
    char time[6];
    int steps[100];
    int count; 

    while (fgets( line, buffer , file)){
        tokeniseRecord(line,",",date,time,steps);

        strcpy(Fitness[counter].date,date);
        strcpy(Fitness[counter].time,time);
        strcpy(Fitness[counter].steps,steps);
        counter++;
    }
    fclose(file);

}