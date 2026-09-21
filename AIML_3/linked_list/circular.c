#include<stdio.h>
#include<stdlib.h>

// create node structure
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



void display(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList : ");
    do{
        printf("%d  ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

// function to insert at begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    struct node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    newNode->next = head;
    head = newNode;
    temp->next = head;
}

// function to insert at end
void insert_at_end(int data){
    struct node *newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }

    struct node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertPosition(int data, int pos){
    struct node *newNode = createNode(data);

    if(pos == 1){
        head = newNode;
        newNode->next = head;
    }

    struct node *temp = head;
    int i = 1;
    while (i < pos-1){
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        printf("\ninvailed position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBegin(){
    struct node *temp = head;

    if (head->next == temp){
        head = NULL;
        printf("\nhead deleted\n");
        return;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
}

void deleteEnd(){
    struct node *temp = head;

    if(head->next == temp){
        head = NULL;
        return;
    }

    while(temp->next->next != head){
        temp = temp->next;
    }

    temp->next = head;
    

}

int main(){

}