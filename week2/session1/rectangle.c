#include <stdio.h>

int main(){
    int length;
    int breadth;
    int area;

    printf("enter length: \n");
    scanf("%d", &length);

    printf("entrer breadth: \n");
    scanf("%d", &breadth);

    area = length * breadth;

    printf("your area is %d", area);

    return 0;

}