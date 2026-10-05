#include<stdio.h>

// bubble sort
void bubble_sort(int arr[], int n){
    for(int i = 0; i < n; i++){

        for(int j = 0; j < n-i-1; j++){

            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// function to display array
void display(int arr[], int n){
    printf("\nArray : ");
    for(int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {3,2,5,1,4,7,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("\nBefore sorting:-");
    display(arr, n);

    bubble_sort(arr, n);
    
    printf("\nAfter sorting:-");
    display(arr, n);
}