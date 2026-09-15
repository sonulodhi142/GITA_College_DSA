#include<stdio.h>
#include<ctype.h>
#define max 20

int stack[max];
int top = -1;

// function to evaluate the postfix expression
int post_eval(char postfix[]){
    int i = 0, a, b, result = 0;

    //scan all tokens left to right
    while(postfix[i] != '\0'){

        char ch = postfix[i];
        i++;

        if( isdigit(ch)){
            ++top;
            stack[top] = ch - '0';
        }
        else{
            a = stack[top];
            top--;
            b = stack[top];
            top--;

            switch (ch)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '^':
                result = a ^ b;
                break;
            default:
                printf("\nOperation is invailed\n");
                return -1;
                break;
            }
            top++; 
            stack[top] = result;
        }
    }
    return stack[top];
}

int main(){
    char postfix[max];
    printf("Enter Postfix Expression : ");
    scanf("%s", postfix);

    printf("Result = %d\n", post_eval(postfix));
    return 0;
}