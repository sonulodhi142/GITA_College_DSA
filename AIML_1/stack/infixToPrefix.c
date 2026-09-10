#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 10

char stack[max];
int top = -1;

// function to reverse expression
void reverse(char exp[]){
    int size = strlen(exp);
    for(int i = 0; i < size/2; i++){
        char temp = exp[i];
        exp[i] = exp[size-1-i];
        exp[size-i-1] = temp;
    }

    for(int i = 0; i<size; i++){
        if(exp[i] == '(') exp[i] = ')';
        else if(exp[i] == ')') exp[i] = '(';
    }
}

// function to check the precendence of operatior
int precendence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

// function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]){
    int i = 0, j = 0;

    while(infix[i] != '\0'){

        char ch = infix[i];
        i++;

        if(isalnum(ch)){
            postfix[j] = ch;
            j++;
        }
        else if(ch == '('){
            top++;
            stack[top] = ch;
        }
        else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        }
        else{
            while(top != -1 && precendence(stack[top]) >= precendence(ch)){
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }
    // pop out all element form the stack and add to postfix
    while(top != -1){
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
}

int main(){
    char infix[max], postfix[max];
    printf("Enter infix expression : ");
    scanf("%s", infix);

    reverse(infix);
    infixToPostfix(infix, postfix);
    reverse(postfix);
    
    printf("\nprefix = %s\n", postfix);
}