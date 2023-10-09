#include <stdio.h>

int main(){
    // setting up 15 slots of memory for a string 
    char name[15];
    // to get the input from the user
    printf("helllo, please enter ur name: ");
    //take the user input and store into name
    scanf("%s",name);
    //prints the user's name
    printf("your name is %s\n",name);

    return 0;
}