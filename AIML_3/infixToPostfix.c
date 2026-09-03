#include<stdio.h>
#include<ctype.h>
#define max 20

char stack[max];
int top = -1;

int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infix_to_postfix(char infix[], char postfix[]){
    int i = 0, j = 0;
    while (infix[i] != '\0'){

        char ch = infix[i++];

        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '('){
            stack[++top] = ch;
        }
        else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j++] = stack[top];
                top--;
            }
            top--;
        }
        else{
            while(top != -1 && precedence(stack[top]) >= precedence(ch)){
                postfix[j++] = stack[top];
                top--;
            }
            stack[++top] = ch;
        }  
    }
    while (top != -1)
    {
        postfix[j++] = stack[top];
        top--;
    }
    postfix[j] = '\0';
}

int main(){
    char infix[max], postfix[max];
    printf("Enter infix expression : ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix : %s", postfix );
    return 0;
}