#include <stdio.h>

int main() {
    int a;
    printf("enter which optiion u would like to choose: \n");
    scanf("%d",&a);

    if ((a>=0)&&(a<4)){
        switch (a)
        {
            case 0:     printf ("Option 0 has been selected\n");
            break;

            case 1:     printf ("Option 1 has been selected\n");
            break;

            case 2:     printf("you have selected option 2\n");
            break;

            case 3:     printf("option 3 has been selected!!\n");
            break;

            default:    printf ("A different option has been selected\n");
        }
    }
    else{
        printf("invalid input: \n");
    }
}