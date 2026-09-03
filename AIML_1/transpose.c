#include<stdio.h>
#define max 20

// function to create sparse matrix
void create_sparse(int sparse_matrix[max][max], int row, int col){
    int i, j;
    printf("\nEnter %d X %d Matrix :\n", row, col);
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
}

// function to Display Matrix
void Display_matrix(int sparse_matrix[max][max], int row, int col){
    int i, j;
    printf("\nDisplay %d X %d Matrix :\n", row, col);
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            printf("%d  ", sparse_matrix[i][j]);
        }
        printf("\n");
    }
}

// function to create sparse in triplet representation
void Triplet_rep(int sparse_matrix[max][max], int Trip_rep[max][3], int row, int col){
    int i, j, k = 1;
    Trip_rep[0][0] = row;
    Trip_rep[0][1] = col;
    
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            if(sparse_matrix[i][j] != 0){
                Trip_rep[k][0] = i;
                Trip_rep[k][1] = j;
                Trip_rep[k][2] = sparse_matrix[i][j];
                k++;
            }
        }
    }
    Trip_rep[0][2] = k-1;
}

// function to Display Triplet Representation
void Display_trip_rep(int Trip_rep[max][3]){
    int i, k = Trip_rep[0][2];
    printf("\nDisplay Tiplet rep.....\n");
    printf("Row\tCol\tValue\n");
    printf("--------------------------\n");
    for(i = 0; i <= k; i++){
        printf("%d\t%d\t%d\t\n", Trip_rep[i][0],Trip_rep[i][1],Trip_rep[i][2]);
    }
}

// function to tranpose a triplet representation
void Transpose_trip(int trip[max][3], int transpose[max][3]){
    int i, j, k=1, row, col, value;

    // get row and col
    row = trip[0][0];
    col = trip[0][1];
    value = trip[0][2];

    // swap row and col
    transpose[0][0] = col;
    transpose[0][1] = row;
    transpose[0][2] = value;

    for(i = 0; i < col; i++){
        for(j = 0; j <= value; j++){
            if(trip[j][1] == i){
                transpose[k][0] = trip[j][1];
                transpose[k][1] = trip[j][0];
                transpose[k][2] = trip[j][2];
                k++;
            }
        }
    }
    transpose[0][2] = k-1;
}

// Addition of two triplet representation
void trip_addition(int a[max][3], int b[max][3], int c[max][3]){
    int i = 1, j = 1, k = 1;

    // check equality of row and col of triplet a and b
    if(a[0][0] != b[0][0] && a[0][1] != b[0][1]){
        printf("\nAddition is not possible\n");
        return;
    }
    
    // get row and col 
    int row = a[0][0];
    int col = a[0][1];

    // store in resultant triplet
    c[0][0] = row;
    c[0][1] = col;

    // get number of non Zero values from a and b
    int valueA = a[0][2];
    int valueB = b[0][2];

    while(i <= valueA && j <= valueB){

        // check similer row's and col's value
        if(a[i][0] == b[j][0] && a[i][1] == b[j][1] ){
            int sum = a[i][2] + b[j][2];
            if(sum != 0){
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            } 
            i++;
            j++;
        }
        // check which one row having smaller value
        else if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1] )){
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
        }
        else{
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
        }
    }
    // add rest of the rows to Resultant triplet from a
    while(i <= valueA){
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
        i++;
    }
    // add rest of the rows to Resultant triplet from b
    while(j <= valueB){
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        k++;
        j++;
    }
    // add final non Zero values
    c[0][2] = k-1;
}


int main(){
    int sparse_matrix[max][max], row, col;

    int A[max][max], B[max][max];
    int a[max][3], b[max][3], c[max][3];

    printf("Enter number of rows :");
    scanf("%d", &row);
    printf("Enter number of cols :");
    scanf("%d", &col);

    printf("Enter value for A : \n");
    create_sparse(A, row, col);
    printf("Enter value for B : \n");
    create_sparse(B, row, col);

    Display_matrix(A, row, col);
    Display_matrix(B, row, col);

    Triplet_rep(A, a, row, col);
    Triplet_rep(B, b, row, col);

    Display_trip_rep(a);
    Display_trip_rep(b);

    trip_addition(a, b, c);

    Display_trip_rep(c);

    // create_sparse(sparse_matrix, row, col);
    // Display_matrix(sparse_matrix, row, col);

    // int trip_rep[max][3];
    // Triplet_rep(sparse_matrix, trip_rep, row, col);
    // Display_trip_rep(trip_rep);

    // int transpose[max][3];
    // Transpose_trip(trip_rep, transpose);
    // Display_trip_rep(transpose);
}