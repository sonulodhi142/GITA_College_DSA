#include<stdio.h>
#define max 20

int stack[max];
int top = -1; 

int precendence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 1;
}

