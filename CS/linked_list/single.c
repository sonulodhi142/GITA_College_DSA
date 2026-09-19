#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert at begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;

    printf("\n%d inserted at begin\n", data);
}

// function to display all elements
void display(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList : ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//function to insert at end
void insert_at_end(int data){
    struct node* newNode=createNode(data);
    if(head==NULL){
        head = newNode;

    }
}    
int main(){
 insert_at_begin(50);
    insert_at_begin(60);
    insert_at_begin(70);
    display();
    
    return 0;
}