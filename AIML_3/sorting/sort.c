#include<stdio.h>

// bubble sort
void bubble_sort(int arr[], int n){

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){

            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
}

void display(int arr[], int n){
    printf("\nSort : ");
    for(int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// selection sort
void selection_sort(int arr[], int n){

    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// insertion sort
void insertion_sort(int arr[], int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {7,8,4,3,2,1,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, n);

    display(arr, n);
}