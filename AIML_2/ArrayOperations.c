#include<stdio.h>
#define max 50
int arr[max];
int size = 0;

// Function to Insert at end
int Insert_at_end(){
    if(size == max){
        printf("\nArray is full...\n");
        return 0;
    }
    else{
        printf("\nEnter value to Insert At End : ");
        scanf("%d", &arr[size]);
        size++;
        printf("\nValue Inserted Successfully...\n");
    }
}

// Function to display array elements
int Display(){
    if(size == 0){
        printf("\nArray is empty..\n");
        return 0;
    }
    else{
        printf("\n Array elemets arr: ");
        for(int i = 0; i < size; i++){
            printf("%d  ", arr[i]);
        }
        printf("\n\n");
    }
}

// Function to Insert at index
int Insert_at_index(){
    int value, idx;
    if(size == max){
        printf("\nArray is full..\n");
        return 0;
    }
    else{
        printf("\nEnter the index (0 to size) : ", size);
        scanf("%d", &idx);
        printf("\nEnter the value : ");
        scanf("%d", &value);
        if(idx >= 0 && idx <= size){
            for(int i = size; i > idx; i--){
                arr[i] = arr[i-1];
            }
            arr[idx] = value;
            size++;
            printf("\n%d is successfully inserted at %d index... \n", value, idx);
        }
    }
}


// function to Delete element from end
int Delete_from_end(){
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        size--;
        printf("\nElement is delect successfully from end\n");
    }
}

// Function to Delete Element
int Delete_element(){
    int element, i, j, found = 1;
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        printf("\nEnter the element to delete : ");
        scanf("%d", &element);
        for(i = 0; i< size; i++){
            if(arr[i] == element){
                for(j = i; j < size-1; j++){
                    arr[j] = arr[j+1];
                }
                found = 0;
                size--;
                printf("\nElement is delete successfully...\n");
            }
        }
    }
    if(found){
        printf("\nElement is not exist in the array...\n");
    }
}

// Function to search element in array (linear Search);
int Search(){
    int element, i, found = 1;
    if(size == 0){
        printf("\nArray is empty....\n");
        return 0;
    }
    else{
        printf("\nEnter element to search : ");
        scanf("%d", &element);
        for(i = 0; i < size; i++){
            if(arr[i] == element){
                printf("\nElement is found at index : %d\n", i);
                found = 0;
            }
        }
    }
    if(found){
        printf("\nElement is not found\n");
    }
}

int main(){
    int choice;
    while (1)
    {
        printf("\n==============Array operation============\n\n");
        printf("1. Insert at end.\n");
        printf("2. Display.\n");
        printf("3. Insert at index.\n");
        printf("4. Delete from end.\n");
        printf("5. Delete element.\n");
        printf("6. Search (linear).\n");
        printf("7. Exit program.\n");
        printf("\nEnter option (1 to 7) : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Insert_at_end();
            break;
        case 2:
            Display();
            break;
        case 3:
            Insert_at_index();
            break;
        case 4:
            Delete_from_end();
            break;
        case 5:
            Delete_element();
            break;
        case 6:
            Search();
            break;
        case 7:
            printf("\nProgram terminated\n\n");
            return 0;
            break;
        default:
        printf("\nIn-vailed Option....\n");
            break;
        }
    }
    
}