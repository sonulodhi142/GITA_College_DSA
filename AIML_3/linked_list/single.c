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
        printf("\ninvailed position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\n%d is inseted at %d\n", data, pos);
}

// function to delete element from begin
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

// function to delete from end
void delete_from_end(){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("\n%d deleted from end\n", temp->data);
    free(temp);
}

// function to delete from position
void delete_from_position(int pos){
    if(head == NULL){
        printf("\nList is empty\n");
        return;
    }

    if(pos == 1){
        delete_from_begin();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    int i = 1;
    while(i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL){
        printf("\ninvailed position\n");
        return;
    }
    prev->next = temp->next;
    printf("\n%d deleted from %d position\n", temp->data, pos);
    free(temp);
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
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("\nElement is not found\n");
    }
    else{
        printf("\n%d found at %d position\n", target, i);
    }
}

int main(){
  int option, value, pos;
  while(1){
    printf("\nlinked list operations\n\n");
    printf("1. insert at begin.\n");
    printf("2. insert at end\n");
    printf("3. insert at position.\n");
    printf("4. delete from begin.\n");
    printf("5. delete from end\n");
    printf("6. delete from position\n");
    printf("7. search element\n");
    printf("8. display\n");
    printf("9. exit programe\n");

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
            printf("Enter Position to insert: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);
            insert_at_position(pos, value);
            break;
        case 4:
            delete_from_begin();
            break;
        case 5:
            delete_from_end();
            break;
        case 6:
            printf("Enter Position to delete: ");
            scanf("%d", &pos);
            delete_from_position(pos);
            break;
        case 7:
            printf("Enter value to search : ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            printf("\nProgram terminated successfully\n");
            return 0;
        default:
            printf("\ninvailed option\n");
    }
  }
}