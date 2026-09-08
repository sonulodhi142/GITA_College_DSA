#include<stdio.h>
#include<ctype.h>
#define max 20

char stack[max];
int top = -1;

int precedence(char ch){
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

        // to handle the operands
        if(isalnum(ch)){
            postfix[j] = ch;
            j++;
        }
        else if( ch == '('){
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
            while(top != -1 && precedence(stack[top]) >= precedence(ch)){
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }
    // to pop all elements from the stack and add to the postfix expression
    while(top != -1){
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
}

int main(){
    char infix[max], postfix[max];
    printf("Enter the infix expression : ");
    scanf("%s", infix); // get infix expression from the user

    infix_to_postfix(infix, postfix); // funtion call

    printf("postfix = %s\n", postfix); // display postfix expression
}