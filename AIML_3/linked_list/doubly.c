#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

// global pointers
struct node *head;
struct node *tail;

struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// function to insert at begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    newNode->next = head;

    if(head != NULL){
        head->prev = newNode; 
    }
    else{
        tail = newNode;
    }

    head = newNode;
    printf("\n%d inserted at begin\n", data);
}

// function to insert at end
void insert_at_end(int data){
    struct node *newNode = createNode(data);

    newNode->prev = tail;

    if(tail != NULL){
        tail->next = newNode;
    }
    else{
        head = newNode;
    }
    tail = newNode;
}

// function to delete from begin
void delete_from_begin(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    else{
        tail = NULL;
    }
    printf("\n%d deleted from begin\n", temp->data);
    free(temp);
}

// function to display all node's data
void display(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *temp = head;
    printf("list (forward) : head -> ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("prev\n");

    temp = tail;
    printf("list (backward) : prev -> ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("head\n");
}

int main(){
    insert_at_begin(44);
    insert_at_begin(55);
    insert_at_end(78);
    insert_at_end(33);
    display();
    return 0;
}