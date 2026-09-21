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


// function to insert begin
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;

    printf("\n%d inserted at begin\n", data);
}

// function to display all nodes
void display(){
    if(head == NULL){
        printf("\nList is empty\n");
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

// function to insert node at end
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
    printf("\n%d inserted at end", data);
}

// function to insert at given position
void insert_at_position(int data, int pos){
    struct node *newNode = createNode(data);
    
    if(pos == 1){
        insert_at_begin(data);
        return;
    }

    struct node *temp = head;
    int i = 1;
    while(i < pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        printf("\nInvailed position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\n%d inserted at %d position\n", data, pos);
}

// function to delete from begin
void delete_from_begin(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("\n%d deleted from begin\n", temp->data);
}

// function to delete from end
void delete_from_end(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    if(head->next == NULL){
        printf("\n%d is deleted from end\n", head->data);
        head = NULL;
        return;
    }
    struct node *prev = NULL;
    struct node *temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("\n%d is deleted from end\n", temp->data);
}

// function to delete from given position
void delete_from_position(int pos){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    if(pos == 1){
        printf("\n%d is deleted from 1 position\n", head->data);
        head = head->next;
        return;
    }
    struct node *prev = NULL;
    struct node *temp = head;
    int i = 1;
    while(i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    printf("\n%d is deleted from %d position\n", temp->data, pos);
}

// function to search element
void search(int target){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    int i = 1;
    while(temp != NULL && temp->data != target){
        temp =temp->next;
        i++;
    }
    if(temp == NULL){
        printf("\n%d is not found\n", target);
    }
    else{
        printf("\n%d found at %d position\n", target, i);
    }
}

int main(){
    insert_at_begin(50);
    insert_at_begin(70);
    insert_at_begin(80);
    insert_at_begin(90);
    display();
    return 0;
}