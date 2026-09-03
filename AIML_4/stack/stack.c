#include<stdio.h>
#define max 10

int stack[max];
int top = -1;

int IsEmpty(){
    return top == -1;
}

int IsFull(){
    return top == max-1;
}

void push(int n){
    if(IsFull()){
        printf("\nStack is overflow \n");
        return;
    }
    else{
        stack[++top] = n;
        printf("\n%d is inserted\n", n);
    }
}

void pop(){
    if(IsEmpty()){
        printf("\nStack is underflow\n");
        return;
    }
    else{
        printf("\n%d is deleted\n", stack[top--]);
    }
}

void peek(){
    if(IsEmpty()){
        printf("\nStack is underflow\n");
        return;
    }
    else{
        printf("\nTop = %d\n", stack[top]);
    }
}

void display(){
    if(IsEmpty()){
        printf("\nStack is underflow\n");
        return ;
    }
    else{
        printf("\nStack : ");
        for(int i = top; i >= 0; i--){
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, n;
    while (1){
        printf("\n=============== stack operations =============\n\n");
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to push : ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nProgram terminated...\n");
            return 0;
            break;
        default:
            printf("\nIn-Vailed option..\n");
            break;
        }
    }
}