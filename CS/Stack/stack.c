#include<stdio.h>
#define max 10

int stack[max];
int top = -1;

// function to check stack is empty or not
int isEmpty(){
    return top == -1;
}
// function to check stack is full or not
int isFull(){
    return top == max-1;
}

// push function
void push(int n){
    if(isFull()){
        printf("\nStack is overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = n;
        printf("\n%d is inserted\n", n);
    }
}

// pop function
void pop(){
    if(isEmpty()){
        printf("\nStack is underflow\n");
        return;
    }
    else{
        printf("\n%d is deleted\n", stack[top]);
        top--;
    }
}

// peek functon
void peek(){
    if(isEmpty()){
        printf("\nStack is underflow\n");
        return;
    }
    else{
        printf("\nTop = %d\n", stack[top]);
    }
}

// display functon
void display(){
    int i;
    if(isEmpty()){
        printf("\nStack is underflow\n");
        return;
    }
    else{
        printf("\nStack : ");
        for(i = top; i>=0; i--){
            printf("%d  ", stack[i]);
        }
        printf("\n");
    }
}



int main(){
    int choice, value;
    while (1)
    {
       printf("\n============= Stack operations ============\n\n");
       printf("1. push.\n"); 
       printf("2. pop.\n"); 
       printf("3. peek.\n"); 
       printf("4. display.\n"); 
       printf("5. exit.\n"); 
        printf("Enter option : ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: pop(); break;
        case 3: peek(); break;
        case 4: display(); break;
        case 5: printf("terminated"); return 0;
        default:
            break;
        }
    }
    
}
