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
        printf("\n%d is deleted from begin\n", delete->data);
        free(delete);
    }
}

// function to delete end
void delete_from_end(){
    struct node *temp = head;
    struct node *delete = head; 
    if(head == NULL){
        printf("\nList is empty");
        return;
    }
    if(head->next == head){
        head = NULL;
    }
    else{
        while (temp->next->next != head){
            temp = temp->next;
        }
        delete = temp->next;
        temp->next = head;
    }
    printf("\n%d deleted from end\n", delete->data);
    free(delete);
}

// function to search element in list
void search(int target){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    int i = 1;
    do{
        if(temp->data == target){
            printf("\n%d found at %d position\n", target, i);
            return;
        }
        i++;
        temp = temp->next;
    }while(temp != head);
    printf("\n%d is not found\n", target);
}


int main(){
  int option, value, pos;
  while(1){
    printf("\n==== Circular linked list =======\n\n");
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