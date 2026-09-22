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
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct node *temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
    printf("\n%d inserted at begin", data);
}

// function to display all nodes data
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
        } while(temp != head);
        printf("head \n");
    }
}

// function to insert at end
void insert_at_end(int data){
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
        temp->next = newNode;
        newNode->next = head;
        printf("\n%d inserted at end\n", data);
    }
}

void delete_from_begin(){
    struct node *delete = head;
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    if(head->next == head){
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        printf("\n%d is deleted from end\n", delete->data);
        free(delete);
    }
}
int main(){
    insert_at_begin(500);
    insert_at_begin(500);
    insert_at_begin(500);
    insert_at_begin(500);
    insert_at_end(50);
    display();
    delete_from_begin();
    display();
    return 0;
}