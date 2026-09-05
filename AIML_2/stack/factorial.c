#include<stdio.h>

// find a factorail of given number using recursion.
int factorail(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    
    return n * factorail(n-1);
}

// print N to 1 using recursion. if n = 5 : output => 5 4 3 2 1

int main(){
    int n;
    printf("Enter the value : ");
    scanf("%d", &n);
    printf("factorial of %d : %d\n", n, factorail(n));
    return 0;
}