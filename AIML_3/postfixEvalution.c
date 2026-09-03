#include<stdio.h>
#include<ctype.h>
#define max 20

int stack[max];
int top = -1;

// function to evaluate postfix expression
int postfix_eval(char postfix[]){
    int i = 0, value1, value2, result = 0;
    while (postfix[i] != '\0'){
        char ch = postfix[i];
        i++;
        if(isdigit(ch)){
            stack[++top] = ch - '0';
        }
        else{
            value1 = stack[top];
            top--;
            value2 = stack[top];
            top--;
            switch (ch)
            {
            case '+':
                result = value1 + value2;
                break;
            case '-':
                result = value1 - value2;
                break;
            case '*':
                result = value1 * value2;
                break;
            case '/':
                result = value1 / value2;
                break;
            default:
                printf("In-vailed operator");
                break;
            }
            stack[++top] = result;
        }
    }
    return stack[top];
}

int main(){
    char postfix[max];
    printf("Enter postfix expression : ");
    scanf("%s", postfix);
    printf("value = %d", postfix_eval(postfix));
}