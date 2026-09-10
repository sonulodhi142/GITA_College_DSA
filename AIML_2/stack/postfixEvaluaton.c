#include<stdio.h>
#include<ctype.h>
#define max 20

int stack[max];
int top = -1;

// function to evaluate postfix expression
int postfix_eval(char postfix[]){
    int i = 0, a, b, result;

    while(postfix[i] != '\0'){

        char ch = postfix[i];
        i++;

        if(isdigit(ch)){
            stack[++top] = ch - '0';
        }
        else{
            b = stack[top--];
            a = stack[top--];

            switch(ch){
                case '^': result = a^b; break;
                case '*': result = a*b; break;
                case '/': result = a/b; break;
                case '+': result = a+b; break;
                case '-': result = a-b; break;
                default: printf("invailed oprerator"); return 0;
            }
            stack[++top] = result;
        }
    }
    return stack[top];
}

int main(){
    char postfix[max];
    printf("Enter postfix expression:");
    scanf("%s", postfix);

    printf("result = %d", postfix_eval(postfix));
    return 0;
}