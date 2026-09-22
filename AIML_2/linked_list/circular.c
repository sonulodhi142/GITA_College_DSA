#include<stdio.h>
#include<stdlib.h>

// single linked list node
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
    }
    printf("\n%d inserted at begin\n", data);
}

// function to display all elements
void display(){
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        struct node *temp = head;
        printf("\nList : ");
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("NULL\n");
    }
}

int main(){
    insert_at_begin(89);
    insert_at_begin(89);
    insert_at_begin(89);
    insert_at_begin(89);
    display();
    return 0;
}