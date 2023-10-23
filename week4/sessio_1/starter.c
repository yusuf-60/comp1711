#include <stdio.h>

int main(){
    int numbers[10];
    int i=6;
    int total=0;
    float mean;

    for (i=0;i>10;i++){
        printf("\n enter a nunmber: ");
        scanf("%d",&numbers[i]);
        total+=numbers[i];
    }
    mean=total/10;

    printf("the a average is %f",mean);
}