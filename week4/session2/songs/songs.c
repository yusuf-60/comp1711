#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Holds the data for a song such as artist, title and year.
 *
 */
typedef struct
{
    int position;
    char artist[100];
    char title[100];
    char year[4];
} SONG_DATA;

/**
 * @brief Splits a line from song_data.txt into the separate data. This is adapted from the coursework code.
 *
 * @param input the line which will be split / the line from the file 
 * @param delimiter the character which deliminates (splits up) the data
 * @param pos a pointer to where it should store the position / 
 * @param artist a pointer to where it should store the artist
 * @param title a pointer to where it should store the title
 * @param years a pointer to where it should store the years
 */

// to return multiple data, we return with pointers

void tokeniseRecord(const char *input, const char *delimiter, char *pos, char *artist, char *title, char *years)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(pos, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(artist, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(title, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(years, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

int main()
{
    SONG_DATA songs[1000]; // making an array of 100 song_data structs in an array called songs
    int buffer_size = 2500; // numbers just need lots of space and its fine 
    char line[buffer_size]; // 
    int counter=0;

    FILE *input = fopen("song_data.txt", "r"); // opening the file 

    // creating some temporary storage:
    // pos will be converted to an int, but we'll be getting it as a string
    char pos[40];
    char artist[1000];
    char title[1000];
    char year[40];
    int a = 0;
    while (fgets(line, buffer_size, input)) // to read everything out the file
    {   
        // first we will get the info from the line
        tokeniseRecord(line,",",pos,artist,title,year);
        // but then what??

        strcpy(songs[counter].artist,artist);
        strcpy(songs[counter].title,title);
        strcpy(songs[counter].year,year);
        songs[counter].position = atoi(pos);
        counter++;
    }

    //count how many total songs you read in
    printf("total songs is %d\n",counter);

    for (a;a<3;a++){
        printf("the artist is : %s" , songs[a].artist);
        printf("the title is : %s",songs[a].title);
        printf("/""%s",songs[a].year);
        printf("/""%d\n",songs[a].position);
    }   
    fclose(input);
}