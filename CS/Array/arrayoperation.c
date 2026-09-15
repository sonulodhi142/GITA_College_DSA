#include<stdio.h>
#define max 50
int arr[max];
int size = 0;

// function to insert value in array at end
int Insert(){
    int value;
    if(size == max){
        printf("\nArray is full..\n");
        return 0;
    }
    else{
        printf("\nEnter the value:");
        scanf("%d", &arr[size]);
        size++;
        printf("\nValue inserted successfully...\n");
    }
}

// Function to display all value of array
int Display(){
    int i;
    if(size == 0){
        printf("\nArray is empty..\n");
        return 0;
    }
    else{
        printf("\nArra vaues : \n\n");
        for(i = 0; i < size; i++){
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
}

// Function to insert at given Index
int InsertAtIndex(){
    int i, idx, value;
    if(size == max){
        printf("\nArray is full..\n");
        return 0;
    }
    else{
        printf("\nEnter Index (0 to %d);", size);
        scanf("%d", &idx);
        printf("\nEnter value : ");
        scanf("%d", &value);
        for(i = size; i>idx; i--){
            arr[i] = arr[i-1];
        }
        arr[idx] = value;
        size++;
        printf("\nValue inserted successfully...\n");
    }
}

// Delete from End
int Delete(){
    if(size == 0){
        printf("\nArray is empty..\n");
        return 0;
    }
    else{
        size--;
        printf("\nValue deleted successfully from end\n");
    }
}

// function to delete element
int Delete_element(){
    int value, i, j, found = 1;
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        printf("\nEnter the element to delete : ");
        scanf("%d", &value);
        for(i = 0; i<size; i++){
            if(arr[i] == value){
                for(j = i; j < size-1; j++){
                    arr[j] = arr[j+1];
                }
                size--;
                found = 0;
                printf("\nElement delete successfully...\n");
            }
        }
    }
    if(found){
        printf("\nElement is not found in array...\n");
    }
}

// Function to Search element is array (linear Search)
int Search(){
    int value, i, found = 1;
    if(size == 0){
        printf("\nArray is empty...\n");
        return 0;
    }
    else{
        printf("\nEnter element to Search : "); 
        scanf("%d", &value); // Get value from the user
        // loop to Traverse over array
        for(i = 0; i<size; i++){
            if(arr[i] == value){ // if value is found
                printf("\nElement is found at index : %d\n", i);
                found = 0;
            }
        }
    }
    if(found){
        printf("\nElement is not found in array...\n");
    }
}

int main(){
    int option;
    while (1)
    {
        printf("\n===============ARRAY OPERATIONS===========\n\n");
        printf("1. Insert at End.\n");
        printf("2. Display.\n");
        printf("3. Insert at Index.\n");
        printf("4. Delete from End.\n");
        printf("5. Delete Element.\n");
        printf("6. Search Element.\n");
        printf("7. Exit program.\n");
        printf("Enter option (1 to 7) : ");
        scanf("%d", &option);

        // Switch statement to call functions
        switch (option)
        {
        case 1:
            Insert();
            break;
        case 2:
            Display();
            break;
        case 3:
            InsertAtIndex();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Delete_element();
            break;
        case 6:
            Search();
            break;
        case 7:
            printf("\nProgram terminated...\n");
            return 0;
            break;
        default:
            printf("\nIn-Vailed Option..\n");
            break;
        }
    }
    
}