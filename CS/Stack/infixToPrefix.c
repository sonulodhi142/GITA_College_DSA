#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20

char stack[max];
int top = -1;

// reverse string
void Reverse_str(char exp[]){
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
        else if(exp[i] == ')'){
            exp[i] = '(';
        }
    }
}
// function to get the precedence of the operator
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
    return -1;
}

// function to convert the infix to postfix experession
void infix_to_postfix(char infix[], char postfix[]){
    int i = 0, j = 0;

    while(infix[i] != '\0'){ 

        char ch = infix[i]; // get the char from the infix
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
            while(top != -1 && precedence(stack[top]) >= precedence(ch)){
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }
    
    // loop to pop all the operator from the stack and add to postfix
    while (top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0'; // add blank char at the end of postfix
}

int main(){
    char infix[max], postfix[max];
    printf("Enter infix expression : ");
    scanf("%s", infix); // get infix expression from the user

    Reverse_str(infix); // reverse infix expression
    infix_to_postfix(infix, postfix); // function call
    Reverse_str(postfix); // reverse postfix expression

    printf("prefix = %s", postfix); // display postfix expression
}