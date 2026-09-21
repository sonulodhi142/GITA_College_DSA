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

//function to insert at end
void insert_at_end(int data){
    struct node* newNode=createNode(data);
    if(head==NULL){
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\n inserted at end\n", data);
}

// function to delete head
void delete_from_begin(){
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        struct node *temp = head;
        head = head->next;
        printf("\n%d is deleted from head\n", temp->data);
        free(temp);
    }
}

// function to delete end
void delete_from_end(){
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        struct node *temp = head;
        struct node *delete = NULL;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        delete = temp->next;
        temp->next = NULL;
        printf("\n%d deleted form end\n", delete->data);
        free(delete);
    }
}

// function to search element
void search(int target){
    if(head == NULL){
        printf("\nList is empty.\n");
    }
    else{
        struct node *temp = head;
        int i = 1;
        while(temp != NULL){
            if(temp->data == target){
                printf("\n%d is found at %d position\n", target, i);
                return;
            }
            i++;
            temp = temp->next;
        }
        printf("\nElement id not found\n");
    }
}


int main(){
    int value, option;
    while(1){
        printf("\n===========single linked list operations=======\n\n");
        printf("1. insert begin.\n");
        printf("2. insert end.\n");
        printf("3. delete begin.\n");
        printf("4. delete end.\n");
        printf("5. diplay.\n");
        printf("6. search.\n");
        printf("7. exit program.\n");

        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            insert_at_begin(value);
            break;
        case 2:
            printf("Enter value : ");
            scanf("%d", &value);
            insert_at_end(value);
            break;
        case 3: delete_from_begin(); break;
        case 4: delete_from_end(); break;
        case 5: display(); break;
        case 6: 
            printf("\nEnter value to search : ");
            scanf("%d", &value);
            search(value);
            break;
        case 7: printf("\nProgram exit successfully\n"); return 0;
        default:
            printf("\ninvailed option");
            break;
        }
    }
}