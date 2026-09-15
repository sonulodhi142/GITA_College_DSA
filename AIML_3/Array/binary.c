#include<stdio.h>
#define size 10

int main(){
    int value;
    int arr[size] = {1, 2, 3, 4 ,5 , 6, 7, 8, 9, 10};

    printf("Enter value to search : ");
    scanf("%d", &value);

    int low = 0;
    int high = size-1;

    while (low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == value){
            printf("\nElement is found at index : %d\n", mid);
            break;
        }
        else if (arr[mid] < value){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    

}