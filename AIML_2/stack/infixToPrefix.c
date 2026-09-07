#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20

char stack[max];
int top = -1; 

int precendence(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

// function to convert infix to postfix expression
void infix_to_postfix(char infix[], char postfix[]){
    int i = 0, j = 0;

    while(infix[i] != '\0'){

        char ch = infix[i];
        i++;

        if(isalnum(ch)){
            postfix[j] = ch;
            j++;
        }
        else if(ch == '('){
            ++top;
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
    // pop all operators from the stack and add to postfix expression
    while(top != -1){
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
}

// fucntion to reverse expression
void Reverse_exp(char exp[]){
    int size = strlen(exp);

    for(int i = 0; i < size/2; i++){
        char temp = exp[i];
        exp[i] = exp[size-1-i];
        exp[size-1-i] = temp;
    }

    for(int i = 0; i<size; i++){
        if(exp[i] == '('){
            exp[i] = ')';
        }
        else if (exp[i] == ')'){
            exp[i] = '(';
        }
    }
}

int main(){
    char infix[max], postfix[max];
    printf("Enter infix expression : ");
    scanf("%s", infix);
    Reverse_exp(infix); // reverse infix expression

    infix_to_postfix(infix, postfix); // convert reverse expresion to postfix
    
    Reverse_exp(postfix); // reverse postfix expression

    printf("prefix expression : %s\n", postfix);
}