#include<stdio.h>
# define max 10

int stack[max];
int top = -1;

// function to check stack is empty or not
int IsEmpty(){
    return top == -1;
}

// function to check stack is full or not
int IsFull(){
    return top == max-1;
}

// function to insert element onto the stack
void push(int n){
    if(IsFull()){
        printf("\nStack overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = n;
        printf("\n%d is inserted", n);
    }
}

// function to delete a element from the stack
void pop(){
    if(IsEmpty()){
        printf("\nStack underflow\n");
        return;
    }
    else{
        printf("\n%d deleted\n", stack[top]);
        top--;
    }
}

// function to get the last inserted value
void peek(){
    if(IsEmpty()){
        printf("\nStack underflow\n");
        return;
    }
    else{
        printf("\nTop = %d\n", stack[top]);
    }
}

// function to display stack elements
void display(){
    int i;
    if(IsEmpty()){
        printf("\nStack underflow\n");
        return;
    }
    else{
        printf("\nStack : ");
        for(i = top; i >= 0; i--){
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int option, value;
    while (1)
    {
        printf("\n================ Stack Operations================\n\n");
        printf("1. push.\n");
        printf("2. pop.\n");
        printf("3. peek.\n");
        printf("4. display.\n");
        printf("5. exit.\n");
        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &value);
            push(value);
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
            printf("\nProgram terminated successfully\n\n");
            return 0;
        default:
            printf("\nIn-vailed option\n");
            break;
        }
        
    }
    
}