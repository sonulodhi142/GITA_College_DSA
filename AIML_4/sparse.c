#include<stdio.h>
#define max 20

// function to create sparse matrix
int create_sparse(int sparse_matrix[max][max], int row, int col){
    int i, j;
    printf("\nEnter %d X %d Matrix :\n", row, col);
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
}

// function to Display Matrix
int Display_matrix(int sparse_matrix[max][max], int row, int col){
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
int Triplet_rep(int sparse_matrix[max][max], int Trip_rep[max][3], int row, int col){
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
int Display_trip_rep(int Trip_rep[max][3]){
    int i, k = Trip_rep[0][2];
    printf("\nDisplay Tiplet rep.....\n");
    printf("Row\tCol\tValue\n");
    printf("--------------------------\n");
    for(i = 0; i <= k; i++){
        printf("%d\t%d\t%d\t\n", Trip_rep[i][0],Trip_rep[i][1],Trip_rep[i][2]);
    }
}

// fucntion to create Transpose
int Create_transpose(int trip[max][3], int transpose[max][3]){
    int i , j, row, col, value;
    row = trip[0][0];
    col = trip[0][1];
    value = trip[0][2];

    // swap row to col numbers
    transpose[0][0] = col;
    transpose[0][1] = row;
    transpose[0][2] = value;
    int k = 1;
    for(i = 0; i<col; i++){
        for(j = 0; j<= value; j++){
            if(trip[j][1] == i){
                transpose[k][0] = trip[j][1];
                transpose[k][1] = trip[j][0];
                transpose[k][2] = trip[j][2];
                k++;
            }
        }
    }
}


// function to add to sparse matrix
void Triplet_addition(int A[max][3],int  B[max][3], int C[max][3]){

    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]){
        printf("\nAddition is not possible \n");
        return;
    }
    int i=1, j=1, k=1;
    int ValueA = A[0][2];
    int ValueB = B[0][2];

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= ValueA && j <= ValueB)
    {

        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
            int sum = A[i][2] + B[j][2];
            if(sum != 0){
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
        else if(A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            k++;
            i++;
        }
        else {
            C[k][0] = B[i][0];
            C[k][1] = B[i][1];
            C[k][2] = B[i][2];
            k++;
            j++;
        }
    }
    while (i <= ValueA)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        k++;
        i++;
    }
    while (j <= ValueB)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        k++;
        j++;
    }
    C[0][2] = k-1;
}
int main(){
    int row, col, i, j;

    int a[max][max], b[max][max], A[max][3],  B[max][3], C[max][3] ;

    int sparse_matrix[max][max];
    printf("Enter number of rows :");
    scanf("%d", &row);
    printf("Enter number of cols :");
    scanf("%d", &col);
    create_sparse(a, row, col);
    create_sparse(b, row, col);

    Triplet_rep(a, A, row, col);
    Triplet_rep(b, B, row, col);

    Display_trip_rep(A);
    Display_trip_rep(B);

    Triplet_addition(A, B, C);

    Display_trip_rep(C);

    return 0;
}

    // create_sparse(sparse_matrix, row, col);
    // Display_matrix(sparse_matrix, row, col);

    // int trip_rep[max][3];
    // Triplet_rep(sparse_matrix, trip_rep, row, col);
    // Display_trip_rep(trip_rep);

    // int transpose[max][3];
    // Create_transpose(trip_rep, transpose);
    // Display_trip_rep(transpose);

    
    
    
    

    

    // triplet to sparse
    // k = 1;
    // printf("Trip_rep to sparse : \n");
    // for(i = 0; i<row; i++){
    //     for(j = 0; j<col; j++){
    //         if(Trip_rep[k][0] == i && Trip_rep[k][1] == j){
    //             printf("%d  ", Trip_rep[k][2]);
    //             k++;
    //         }
    //         else{
    //             printf("%d  ", 0);
    //         }
    //     }
    //     printf("\n");
    // }

    // transpose Triplet

    // int tranpose[max][3];

    // row = Trip_rep[0][0];
    // col = Trip_rep[0][1];
    // int nonZero = Trip_rep[0][2];

    // // swap row to col
    // tranpose[0][0] = col;
    // tranpose[0][1] = row;
    // tranpose[0][2] = nonZero;
    // k = 1;
    // for(i = 0; i < col; i++){
    //     for(j = 0; j <= nonZero; j++){
    //         if(Trip_rep[j][1] == i){
    //             tranpose[k][0] = Trip_rep[j][1];
    //             tranpose[k][1] = Trip_rep[j][0];
    //             tranpose[k][2] = Trip_rep[j][2];
    //             k++;
    //         }
    //     }
    // }
    // k = nonZero;
    // display transpose
    // printf("\nDisplay tranpose rep.....\n");
    // for(i = 0; i <= k; i++){
    //     printf("%d\t%d\t%d\t\n", tranpose[i][0],tranpose[i][1],tranpose[i][2]);
    // }

// }