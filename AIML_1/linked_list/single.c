#include<stdio.h>
#include<stdlib.h>

// node structure
struct node{
    int data;
    struct node *next;
};

// global pointers
struct node *head = NULL;
struct node *tail = NULL;

// function to create node
struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert head
void insert_at_begin(int data){
    struct node *newNode = createNode(data);

    newNode->next = head;
    if(head == NULL){
        tail = newNode;
    }
    head = newNode;
    printf("\n%d inserted at begin\n", data);
}

// function to insert tail
void insert_at_end(int data){
    struct node *newNode = createNode(data);

    if(tail == NULL){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
    printf("\n%d inserted at end\n", data);
}

// function to display data of all nodes
void display(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    printf("\nList : head -> ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("tail\n");
}

// function to delete from begin
void delete_from_begin(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *deleted = head;
    if(head->next == NULL){
        tail = NULL;
    }
    head = head->next;
    printf("\n%d deleted from begin\n", deleted->data);
    free(deleted);
}

// function to delete from end
void delete_from_end(){
    if(head == NULL){
        printf("\nlist is empty\n");
        return;
    }
    struct node *deleted = tail;
    if(head->next == NULL){
       head = tail = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
    }
    printf("\n%d deleted from end\n", deleted->data);
    free(deleted);
}

// function to search
void search(int target){
    if(head == NULL){
        printf("\nList is empty\n");
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
    printf("\n%d is not found\n", target);
}


int main(){
  int option, value, pos;
  while(1){
    printf("\n==== linked list =======\n\n");
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

