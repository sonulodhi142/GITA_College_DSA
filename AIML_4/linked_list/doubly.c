#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

// global pointers
struct node *head = NULL;
struct node *tail = NULL;

// function to create node
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

// function to delete from end
void delete_from_end(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = tail;
    tail = tail->prev;
    if(tail != NULL){
        tail->next = NULL;
    }
    else{
        head = NULL;
    }
    printf("\n%d deleted from end\n", temp->data);
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

}

// function to search element
void search(int target){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *temp = head;
    int i = 1;
    while(temp != NULL){
        if(temp->data == target){
            printf("\n%d found at %d position\n", target, i);
            return;
        }
        i++;
        temp = temp->next;
    }
    printf("\nelement is not found\n");
}



int main(){
  int option, value, pos;
  while(1){
    printf("\n==== Doubly linked list =======\n\n");
    printf("1. insert at begin.\n");
    printf("2. insert at end\n");
    printf("3. delete from begin.\n");
    printf("4. delete from end\n");
    printf("5. search element\n");
    printf("6. display\n");
    printf("7. exit programe\n");

    printf("\nEnter option : ");
    scanf("%d", &option);

    switch(option){
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_at_begin(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);         

            insert_at_end(value);
            break;
        case 3:
            delete_from_begin();
            break;
        case 4:
            delete_from_end();
            break;
        case 5:
            printf("Enter value to search : ");
            scanf("%d", &value);
            search(value);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("\nProgram terminated successfully\n");
            return 0;
        default:
            printf("\ninvailed option\n");
    }
  }
}