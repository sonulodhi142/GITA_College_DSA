#include<stdio.h>
#include<stdlib.h>


// create a node
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

// function to display all element of list
void display(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList : ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// function to insert node begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;

    printf("\n%d inserted at begin \n", data);
}

// function to insert at end
void insert_at_end(int data){
    struct node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    printf("\n%d inserted at end\n", data);
}

// fucntion to insert at position
void insert_at_position(int pos, int data){
    struct node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct node *temp = head;
    int i = 1;
    while(i < pos-1){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\ninvailed position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\n%d is inseted at %d\n", data, pos);
}
int main(){
    display();

    insert_at_begin(5);
    insert_at_begin(10);

    insert_at_end(50);
    display();
}