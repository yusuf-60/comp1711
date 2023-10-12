#include <stdio.h>

int main(){
    float farenheit;
    float celcius;

    printf("what is the weather in farenheit?: ");
    scanf("%f",&farenheit);

    celcius = (farenheit-32)*5/9;
    printf("the degrees in celcius is %f",celcius);
    return 0;
}