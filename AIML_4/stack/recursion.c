#include<stdio.h>
int factorial(int n){
    // base case
    if(n == 0 || n == 1){
        return 1;
    }

    return n * factorial(n-1); // function call
}
// print numbers N to 1 by using recursion if n = 5 => 5 4 3 2 1
void print_n_to_1(int n){
    if(n == 0){
        return;
    }
    printf("%d ", n);
    print_n_to_1(n-1);
}
// print numbers 1 to N by using recursion if n = 5 => 1 2 3 4 5
void print_1_to_n(int n){
    if(n == 0){
        return;
    }
    print_n_to_1(n-1);
    printf("%d ", n);
}

int main(){
    int n;
    printf("Enter value : ");
    scanf("%d", &n);
    print_n_to_1(n);
    // printf("factorial = %d", factorial(n));
}