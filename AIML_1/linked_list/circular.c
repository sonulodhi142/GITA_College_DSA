#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node *next;
};

// global pointers
struct node *head = NULL;
struct node *tail = NULL;

// function to create node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// function to insert at begin
void insert_at_begin(int data) {

    struct node *newNode = createNode(data);

    // if list is empty
    if (head == NULL) {
        head = tail = newNode;

        // circular connection
        tail->next = head;
    }
    else {
        newNode->next = head;
        head = newNode;

        // maintain circular connection
        tail->next = head;
    }

    printf("\n%d inserted at begin\n", data);
}

// function to insert at end
void insert_at_end(int data) {

    struct node *newNode = createNode(data);

    // if list is empty
    if (head == NULL) {
        head = tail = newNode;

        // circular connection
        tail->next = head;
    }
    else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    printf("\n%d inserted at end\n", data);
}

// function to display all nodes
void display() {

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;

    printf("\nList : head -> ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("head\n");
}

// function to delete from begin
void delete_from_begin() {

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *deleted = head;

    // only one node
    if (head == tail) {
        head = tail = NULL;
    }
    else {
        head = head->next;

        // maintain circular connection
        tail->next = head;
    }

    printf("\n%d deleted from begin\n", deleted->data);

    free(deleted);
}

// function to delete from end
void delete_from_end() {

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *deleted = tail;

    // only one node
    if (head == tail) {
        head = tail = NULL;
    }
    else {

        struct node *temp = head;

        // find node before tail
        while (temp->next != tail) {
            temp = temp->next;
        }

        tail = temp;

        // maintain circular connection
        tail->next = head;
    }

    printf("\n%d deleted from end\n", deleted->data);

    free(deleted);
}

// function to search
void search(int target) {

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;
    int i = 1;

    do {

        if (temp->data == target) {
            printf("\n%d found at %d position\n", target, i);
            return;
        }

        i++;
        temp = temp->next;

    } while (temp != head);

    printf("\n%d is not found\n", target);
}


// main function
int main() {

    int option, value;

    while (1) {

        printf("\n===== CIRCULAR LINKED LIST =====\n\n");

        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Delete from begin\n");
        printf("4. Delete from end\n");
        printf("5. Search element\n");
        printf("6. Display\n");
        printf("7. Exit program\n");

        printf("\nEnter option : ");
        scanf("%d", &option);

        switch (option) {

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
                printf("Enter value to search: ");
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
                printf("\nInvalid option\n");
        }
    }

    return 0;
}