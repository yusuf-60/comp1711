#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <math.h>

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char lowest_date[11];
char lowest_time[60];
char highest_date[11];
char highest_time[60];

char start_time[40];
char end_time[40];
int highest_streak = 0;
int current_streak = 0;
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
    
int read_info(const char *file_name,int *counter, int *mean_steps){
    FITNESS_DATA fitdata[250];
    int buffer = 200;
    char line[buffer];
    int count;
    char date[11];
    char time[60];       
    char steps[10];

    *counter = 0;
    *mean_steps = 0;
    int total_steps = 0;
    float unrounded_mean = 0;

    int lowest_steps;
    int highest_steps;
    int current_streak = 0;
    int highest_streak = 0;
    int difference_index = 0;
    int start_index;


    FILE *file = fopen(file_name , "r");
    if (file == NULL){
        return 1;
    }else{
        printf("File successfully loaded.\n");
    
    while (fgets( line, buffer , file)){

    tokeniseRecord(line,",",date,time,steps);

    strcpy(fitdata[*counter].date,date);
    strcpy(fitdata[*counter].time,time);
    fitdata[*counter].steps = atoi(steps);
    (*counter) =*counter+1;
    }

    lowest_steps=0;
    highest_steps=0;
    for (count=0;count<*counter;count++){
        total_steps += fitdata[count].steps;
        strcpy(lowest_date,(fitdata[count].date));
        strcpy(lowest_time,(fitdata[count].time));
        if (fitdata[count].steps<lowest_steps){
            lowest_steps =fitdata[count].steps;
            //  strcpy(tdetail.date,(fitdata[count].date));
            strcpy(lowest_date,(fitdata[count].date));
            strcpy(lowest_time,(fitdata[count].time));
        }else if(fitdata[count].steps>highest_steps){
            highest_steps = fitdata[count].steps;
            strcpy(highest_date,(fitdata[count].date));
            strcpy(highest_time,fitdata[count].time);
        }
    }
    
    for (int count=0;count<*counter;count++){
        if ((fitdata[count].steps)>500){
            if (current_streak == 0 ){ 
            start_index = count;
            }current_streak++;
        }
        else{
            if(current_streak>highest_streak){
                strcpy(end_time,(fitdata[count-1].date));
                strcat(end_time," ");
                strcat(end_time,(fitdata[count-1].time));
                highest_streak=current_streak;
                difference_index = count;
            }current_streak = 0;
        }
    }
    if (current_streak > highest_streak) {
    strcpy(end_time, fitdata[*counter - 1].date);
    strcat(end_time, " ");
    strcat(end_time, fitdata[*counter - 1].time);
    highest_streak = current_streak;
    }
    strcpy(start_time,(fitdata[difference_index-highest_streak].date));
    strcat(start_time," ");
    strcat(start_time,(fitdata[difference_index-highest_streak].time));

    
    unrounded_mean = (float)total_steps/(*counter);
    *mean_steps = round(unrounded_mean);
    fclose(file);
    return 0;
}
}

// Complete the main function
int main() {
    char file_name[100];
   
    char option;
    int counter = 15 ;
    int mean_steps = 0;
    while(1){
        printf("Menu Options:\nA: Specify filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
        scanf(" %c", &option);
        switch (option){
                case 'A':printf("Input filename: ");scanf("%s",file_name);
                if (read_info(file_name, &counter, &mean_steps) != 0){
                    fprintf(stderr,"Error: Could not find or open the file.\n");
                    exit(1);
                }
                break;
                case 'B':printf("Total records: %d\n",counter);
                break;
                case 'C':
                printf("Fewest steps: %s %s\n",lowest_date,lowest_time);
                break;
                case 'D':
                printf("Largest steps: %s %s\n",highest_date,highest_time);
                break;
                case 'E':   
                printf("Mean step count: %d\n",mean_steps);
                break;
                case 'F':
                printf("Longest period start: %s \n",start_time);
                printf("Longest period end: %s\n", end_time);
                break;
                case 'Q':
                exit(-1);
                default: printf("Invalid choice. Try again.\n");
            }
    }
}

