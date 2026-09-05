#include<stdio.h>

// find a factorail of given number using recursion.
int factorail(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    
    return n * factorail(n-1);
}

// print N to 1 using recursion. if n = 5 : output => 5 4 3 2 1
void print_N_to_1(int n){
    if(n == 0){
        return;
    }
    printf("%d ", n);
    print_N_to_1(n-1);
}

// print 1 to n using recursion. if n = 5 : output => 1 2 3 4 5
void print_1_to_N(int n){
    if(n == 0){
        return;
    }
    print_1_to_N(n-1);
    printf("%d ", n);
}

int main(){
    int n;
    printf("Enter the value : ");
    scanf("%d", &n);
    print_1_to_N(n);
    // print_N_to_1(n);
    // printf("factorial of %d : %d\n", n, factorail(n));
    return 0;
}