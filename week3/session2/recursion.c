#include <stdio.h>


int recursion_1(double int(n)){
    if (n>1){
        n*=recursion_1(n-1);
    }
    return n;
}
int main(){
    double int n;

    printf("enter a value to return the factorial of: \n");
    scanf("%d",&n);

    printf("this is the value returned %d\n",recursion_1(n));
    return 0;
}