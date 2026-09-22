#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *next;
};

// global pointer
struct node *head = NULL;

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// void insert at begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
        printf("%d inserted at begin\n", data);
    }
}

// function to display all elements
void display(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList : ");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("head\n");
}

int main(){
    insert_at_begin(60);
    insert_at_begin(60);
    insert_at_begin(60);
    insert_at_begin(60);
    insert_at_begin(60);
    display();
}