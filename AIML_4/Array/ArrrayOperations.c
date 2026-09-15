#include<stdio.h>
#define max 20
int arr[max];
int size = 0;

// Function to Insert at End
int Insert_at_end(){
    if(size == max){
        printf("\nArray is full...\n");
        return 0;
    }
    else{
        printf("\nEnter the value : ");
        scanf("%d", &arr[size]);
        size++;
        printf("\nValue inserted successfully...\n");
    }
}
// function to display all Elements
int Display(){
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    printf("\nArray Elements are : ");
    for(int i = 0; i< size; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n\n");
}

// Function to insert at index
int Insert_at_index(){
    int value, idx, i;
    if(size == max){
        printf("\nArray is full..\n");
        return 0;
    }
    else{
        printf("\nEnter index (0 to %d ) : ", size);
        scanf("%d", &idx);
        printf("\nEnter value : ");
        scanf("%d", &value);
        for(i = size; i > idx; i--){
            arr[i] = arr[i-1];
        }
        arr[idx] = value;
        size++;
        printf("\n%d is inserted successfully at index %d.\n", value, idx);
    }
}

// Function to delete element from end
int Delete_from_end(){
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        size--; // Decrease size by 1
        printf("\nElement is deleted from the end...\n");
    }
}

// function to element from the array
int Delete_element(){
    int value, i, j, found = 1;
    if(size == 0){
        printf("\nArray is empty...\n");
    }
    else{
        printf("\nEnter value to delete : ");
        scanf("%d", &value);
        for(i = 0; i<size; i++){ // for traverse over the array
            if(arr[i] == value){
                for(j = i; j < size-1; j++){ // for shift element from right to left from the i
                    arr[j] = arr[j+1];
                }
                size--;
                printf("\n%d is deleted from the array..", value);
                found = 0;
            }
        }
    }
    if(found){
        printf("\nElement is not found...\n");
    }
}
// function to search elment in array
int Search(){
    int value, i, found = 1;
    if(size == 0){
        printf("\nArray is empty...\n");
    }
    else{
        printf("\nEnter value to delete : ");
        scanf("%d", &value);
        for(i = 0; i<size; i++){ // for traverse over the array
            if(arr[i] == value){
                printf("Element is found at index : %d\n", i);
                found = 0;
                break;
            }
        }
    }
    if(found){
        printf("\nElement is not found...\n");
    }
}





int main(){
    int option;
    while (1)
    {
        printf("\n=============ARRAY OPERATIONS===============\n\n");
        printf("1. Insert at end.\n");
        printf("2. Display.\n");
        printf("3. Insert at Index.\n");
        printf("4. Delete from end.\n");
        printf("5. Delete Element.\n");
        printf("6. Search Element (linear).\n");
        printf("7. exit program.\n");
        printf("\nEnter option (1 to 7): ");
        scanf("%d", &option);

        switch (option)
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
            printf("\nProgram Terminated...\n");
            return 0;
            break;
        default:
            printf("\nIn-vailed Option...\n");
            break;
        }
    }
    


    return 0;
}