#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL; 

// function to create a node
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
    printf("%d inserted at end\n", data);
}

// function to insert at position
void insert_at_position(int data, int pos){
    struct node *newNode = createNode(data);

    if(pos == 1){
        insert_at_begin(data);
        printf("\n%d is inserted at 1 position\n", data);
        return;
    }
    struct node *temp = head;
    int i = 1;
    while(i < pos-1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("\ninvailed position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\n%d inserted at %d position\n", data, pos);

}

// function to from begin
void delete_from_begin(){
    if(head == NULL){
        printf("\nList is Empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("\n%d deleted from begin\n", temp->data);
    free(temp);
}

// function to delete node from given position
void delete_from_position(int pos){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    if(pos == 1){
        delete_from_begin();
        return;
    }
    struct node *deleteNode = NULL;
    struct node *temp = head;
    int i = 1; 
    while(i < pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL){
        printf("\ninvailed position\n");
        return;
    }
    deleteNode = temp->next;
    temp->next = deleteNode->next;
    printf("\n%d is deleted from %d position\n", deleteNode->data, pos);
    free(deleteNode);
}

// function to delete last node
void delete_from_last(){
    if(head == NULL){
        printf("\nList is Empty\n");
        return;
    }
    if(head->next == NULL){
        printf("\n%d deleted from end", head->data);
        head = NULL;
        return;
    }
    struct node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct node *deleteNode = temp->next;
    temp->next = NULL;
    printf("\n%d deleted from end\n", deleteNode->data);
    free(deleteNode);
}

// function to search element 
void search(int target){
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        int i = 1;
        struct node *temp = head;
        while( temp != NULL ){
            if(temp->data == target){
                printf("%d is found at %d position\n", target, i);
                return;
            }
            i++;
            temp = temp->next;
        }
        printf("\n%d is not found\n",target);
    }
}


int main(){
    insert_at_begin(50);
    insert_at_begin(60);
    insert_at_begin(70);
    insert_at_end(90);
    delete_from_last();
    display();

    insert_at_position(100, 3);
    delete_from_position(3);

    delete_from_begin();
    display();

    insert_at_position(500,1);
    display();
    insert_at_position(50,8);
    display();
}