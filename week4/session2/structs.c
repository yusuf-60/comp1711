#include <stdio.h>
#include <string.h>

//info that you want to package together 
// better than arrasy, since we can store different types of data together 

struct student{
    char name[200];// have be shy to asign loads of strings and dont feel bad
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student;

    
    printf("enter your name\n");
    scanf("%s",new_student.name);
    printf("enter your student id\n");
    scanf("%s",new_student.student_id);    
    printf("enter your mark\n");
    scanf("%u",&new_student.mark);

    //scanf doesnt work with things with spaces in it
    
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}








