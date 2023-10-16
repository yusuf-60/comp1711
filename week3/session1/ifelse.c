#include <stdio.h>

int main() {

    int mark;
    printf("what is your mark?: ");
    scanf("%d",&mark);

    if ((mark >=0) &&(mark<=100))
    {
       if (mark>=70){
        printf("you have achieved a first, well done!!\n");
       }
       else if (mark>=60){
        printf("you have acheived a 2:1 well done!!\n");
       }
       else if (mark>=40){
        printf("you have acheived a pass, welldone\n");
       }
       else{
        printf("you failed\n");
       }
    }
    return 0;
}