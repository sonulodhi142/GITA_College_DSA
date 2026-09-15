#include<stdio.h>

int Factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * Factorial(n - 1);
}

// Write a program to print N to 1 by using recursion : if n = 5 : output => 5 4 3 2 1
int display_n_to_1(int n){
    if(n == 0){
        return 1;
    }
    printf("%d ", n);
    display_n_to_1(n-1);
}

// Write a program to print 1 to n by using recursion : if n = 5 : output => 1 2 3 4 5
int display_1_to_n(int n){
    if(n == 0){
        return 1;
    }
    display_1_to_n(n-1);
    printf("%d ", n);
}
int main(){
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    display_n_to_1(n);
    printf("\n\n");
    display_1_to_n(n);
    // printf("Factorial = %d\n", Factorial(n));
}