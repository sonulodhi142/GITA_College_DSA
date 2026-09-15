#include<stdio.h>
#define max 20
int arr[max];
int size = 0;

// Insert function
int Insert(){
    if(size == max){
        printf("\nArray is full..\n");
        return 0;
    }
    else{
        printf("Enter the value:");
        scanf("%d", &arr[size]);
        size++;
        printf("\nElement added successfully....\n");
    }
}


// Display function
int Display(){
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        printf("\nArray values: ");
        for(int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
    }
}

int Insert_at(){
    if(size == max){
        printf("\narray is full...\n");
        return 0;
    }
    int idx, value;
    printf("Enter the index(0 To %d):", size);
    scanf("%d", &idx);
    printf("Enter value:");
    scanf("%d", &value);
    for(int i = size; i>idx; i--){
        arr[i] = arr[i-1];
    }
    arr[idx] = value;
    size++;
    printf("\nElement Inserted successfully....\n");
}

int Delete(){
    if(size == 0){
        printf("Array is empty...\n");
        return 0;
    }
    else{
        size--;
        printf("\nValue is Deleted from the End...\n");
    }
}

int Delete_value(){
    int i, j, value, found = 1;
    if(size == 0){
        printf("\nArray is Empty...\n");
        return 0;
    }
    else{
        printf("Enter value for Delete :");
        scanf("%d", &value);
        for(i=0; i<size; i++){
            if(arr[i] == value){
                for(j = i; j < size-1; j++){
                    arr[j] = arr[j+1];
                }
                found = 0;
                size--;
                printf("\nValue Delete successfully...\n");
            }
        }
        if(found){
            printf("\nValue is not found in array\n");
        }
    }
}


// search element

int Search(){
    int value, i , found = 1;
    if(size == 0){
        printf("\n Array is empty...\n");
        return 0;
    }
    else{
        printf("Enter a value for search:");
        scanf("%d", &value);
        for(i = 0; i < size; i++){
            if(arr[i] == value){
                printf("Element is found at index : %d\n", i);
                found = 0;
                break;
            }
        }
        if(found){
            printf("\nElement is not found\n");
        }
    }
}


int main(){
    int choice;
    while(1){
        printf("\n===========Array operations==========\n\n");
        printf("1. Insert At End.\n");
        printf("2. Display.\n");
        printf("3. Insert At Index.\n");
        printf("4. Delete from End.\n");
        printf("5. Delete Element.\n");
        printf("6. Search (Linear).\n");
        printf("7. Exit.\n");
        printf("\nEnter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Display();
            break;
        case 3:
            Insert_at();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Delete_value();
            break;
        case 6:
            Search();
            break;
        case 7:
            printf("\nProgram terminated successfully...\n\n");
            return 0;
        default:
            printf("\nIn-vailed Option\n\n");
            break;
        }
    }
}
