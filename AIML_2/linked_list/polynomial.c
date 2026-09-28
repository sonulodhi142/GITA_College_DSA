#include <stdio.h>
#include <stdlib.h>

// node structure
struct node{
    int coff;
    int exp;
    struct node *next;
};

// Create a new node
struct node *createNode(int coff, int exp){
    struct node *newNode  = (struct node *)malloc(sizeof(struct node));

    newNode->coff = coff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Add node in decreasing order of exponent
void addNode(struct node **eq, int coff, int exp){
    struct node *newNode = createNode(coff, exp);
    // Case 1: First node
    if (*eq == NULL){
        *eq = newNode;
    }
    // Case 2: Insert at beginning
    else if ((*eq)->exp < newNode->exp){
        newNode->next = *eq;
        *eq = newNode;
    }
    // Case 3: Insert in middle or end
    else{
        struct node *temp = *eq;
        while (temp->next != NULL && temp->next->exp > newNode->exp){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void display(struct node *eq){
    struct node *temp = eq;
    if (eq == NULL){
        printf("\nEquation is not formed.\n");
        return;
    }

    printf("\nEquation : ");
    while (temp != NULL){
        printf("%dX^%d", temp->coff, temp->exp);
        if (temp->next != NULL){
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Create polynomial
void createEquation(struct node **eq){
    int terms, coff, exp;
    printf("\nEnter Number of terms : ");
    scanf("%d", &terms);

    for (int i = 1; i <= terms; i++){
        printf("\nEnter coefficient and exponent for term %d:\n", i);

        printf("Coff : ");
        scanf("%d", &coff);

        printf("Exp : ");
        scanf("%d", &exp);

        addNode(eq, coff, exp);
    }
}

// Add two polynomials
struct node* addPolynomial(struct node *p1, struct node *p2){
    struct node *result = NULL;

    while (p1 != NULL && p2 != NULL){
        // Same exponent
        if (p1->exp == p2->exp){
            addNode(&result, p1->coff + p2->coff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        // p1 exponent is greater
        else if (p1->exp > p2->exp) {
            addNode(&result, p1->coff, p1->exp);
            p1 = p1->next;
        }
        // p2 exponent is greater
        else{
            addNode(&result, p2->coff, p2->exp);
            p2 = p2->next;
        }
    }
    // Remaining terms of p1
    while (p1 != NULL){
        addNode(&result, p1->coff, p1->exp);
        p1 = p1->next;
    }
    // Remaining terms of p2
    while (p2 != NULL){
        addNode(&result, p2->coff, p2->exp);
        p2 = p2->next;
    }
    return result;
}


int main(){
    struct node *eq = NULL;
    struct node *eq1 = NULL;
    struct node *result = NULL;

    createEquation(&eq);
    display(eq);
    createEquation(&eq1);
    display(eq1);

    result = addPolynomial(eq, eq1);
    display(eq);
    display(eq1);
    display(result);

    return 0;
}