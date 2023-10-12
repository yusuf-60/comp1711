#include <stdio.h>

int main(){
    int user=0 ;

    while (user!=24){
        printf("guess the number ");
        scanf("%d",&user);
        if (user>24){
            printf("the number is too high!! \n");
        }else if(user<24){
            printf("your number is too low!! \n");
        }
    }
    printf("congratulations you have guessed the number correctly!!!😱😱 \n");
    return 0;
}