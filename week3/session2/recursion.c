#include <stdio.h>


int recursion_1(int(n)){
    if (n>1){
        n*=recursion_1(n-1);
    }
    return n;
}
int main(){
    int n;

    printf("enter a value to return the factorial of: \n");
    scanf("%d",&n);

    printf("this is the value returned %d",recursion_1(n));
    return 0;
}