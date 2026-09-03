#include<stdio.h>
int factorial(int n){
    if(n == 0){
        return 1;
    }

    return n * factorial(n-1);
}

int print_n_to_1(int n){
    if(n == 0){
        return 0;
    }
    print_n_to_1(n-1);
    printf("%d ", n);
}
int main(){
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);
    print_n_to_1(n);
    // printf("factorial of %d : %d", n, factorial(n));
    return 0;
}