#include<stdio.h>
#define max 20
// get sparse matrix from user
int create_sparse(int sparse[max][max], int row, int col){
    int i, j;
    printf("\nEnter the %d X %d matrix : \n", row, col);
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &sparse[i][j]);
        }
    }
}

// display sparse matrix 
int Display_sparse(int sparse[max][max], int row, int col){
    int i,j;
    printf("\n %d X %d matrix is : \n", row, col);
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%d  ", sparse[i][j]);
        }
        printf("\n");
    }
}

// Create a triplet representation
int Create_trip_rep(int sparse[max][max], int trip_rep[max][3], int row, int col){
    int i, j, k;
    trip_rep[0][0] = row;
    trip_rep[0][1] = col;
    k = 1;
    for(i = 0; i<row; i++){
        for(j = 0; j<col; j++){
            if(sparse[i][j] != 0){
                trip_rep[k][0] = i;
                trip_rep[k][1] = j;
                trip_rep[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    trip_rep[0][2] = k-1;
}

// Display triplet Representation
int Display_trip_rep(int trip_rep[max][3]){
    int i;
    int k = trip_rep[0][2];
    printf("Triplet Representation : \n");
    printf("row\tcol\tnonZero\n");
    printf("-------------------------------\n");
    for(i = 0; i<=k; i++){
        printf("%d\t%d\t%d\n", trip_rep[i][0], trip_rep[i][1], trip_rep[i][2]);
    }
}

// Transpose of matrix using triplet representation
int Transpose_of_trip(int trip_rep[max][3], int transpose[max][3]){
    int k = 1, i, j, row, col, value;
    // get number of row col and value
    row = trip_rep[0][0];
    col = trip_rep[0][1];
    value = trip_rep[0][2];
    // swap row to col
    transpose[0][0] = col;
    transpose[0][1] = row;
    transpose[0][2] = value;
    // loop to swap row to col in squence
    for(i = 0; i < col; i++){
        for(j = 0; j <= value; j++){
            if(trip_rep[j][1] == i){
                transpose[k][0] = trip_rep[j][1];
                transpose[k][1] = trip_rep[j][0];
                transpose[k][2] = trip_rep[j][2];
                k++;
            }
        }
    }
}

// function to convert triplet representation to sparse
int trip_to_sparse(int trip_rep[max][3]){
    int row = trip_rep[0][0];
    int col = trip_rep[0][1];
    int k = 1,i,j;
    printf("Triplet to Sparse : \n");
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(trip_rep[k][0] == i && trip_rep[k][1] == j){
                printf("%d  ", trip_rep[k][2]);
                k++;
            }
            else{
                printf("%d  ",0);
            }
        }
        printf("\n");
    }
}

void trip_addition(int a[max][3], int b[max][3], int c[max][3] ){
    int i = 1, j = 1, k = 1;

    if(a[0][0] != b[0][0] || a[0][1] != b[0][1]){
        printf("\nAddition is not posible\n");
        return;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int valueA = a[0][2];
    int valueB = b[0][2];

    while (i <= valueA && j <= valueB){
        if(a[i][0] == b[j][0] && a[i][1] == b[j][1]){
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
        else if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])){
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
    while(i <= valueA){
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
        i++;
    }
    while(j <= valueB){
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        k++;
        j++;
    }
    c[0][2] = k-1; 
}

int main(){
    int sparse[max][max], trip_rep[max][3], i, j, k, row, col;

    printf("\nEnter the rows : ");
    scanf("%d", &row);
    printf("\nEnter the cols : ");
    scanf("%d", &col);

    // create_sparse(sparse, row, col);
    // Display_sparse(sparse, row, col);
    // Create_trip_rep(sparse, trip_rep, row, col);
    // Display_trip_rep(trip_rep);
    // int Transpose[max][3];
    // Transpose_of_trip(trip_rep, Transpose );
    // Display_trip_rep(Transpose);
    // trip_to_sparse(Transpose);
    int a[max][max], b[max][max], at[max][3], bt[max][3], ct[max][3];

    create_sparse(a, row, col);
    create_sparse(b, row, col);

    Create_trip_rep(a, at, row, col);
    Create_trip_rep(b, bt, row, col);

    trip_addition(at, bt, ct);
    Display_trip_rep(ct);


    
    

}



















// Addition of two triplet representation of sparse
// int triplet_addition(int a[max][3], int b[max][3], int c[max][3]){
//     int i, j, k;
//     i = j = k = 1;
//     int termA = a[0][2];
//     int termB = b[0][2];
//     c[0][0] = a[0][0];
//     c[0][1] = a[0][1];
//     while (i <= termA && j <= termB)
//     {
//         if(a[i][0] == b[j][0] && a[i][1] == b[j][1]){
//             int sum = a[i][2] + b[j][2];
//             if(sum != 0){
//                 c[k][0] = a[i][0];
//                 c[k][1] = a[i][1];
//                 c[k][2] = sum;
//                 k++;
//             }
//             i++;
//             j++;
//         }
//         else if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1] )){
//             c[k][0] = a[i][0];
//             c[k][1] = a[i][1];
//             c[k][2] = a[i][2];
//             i++;
//             k++;
//         }
//         else{
//             c[k][0] = b[j][0];
//             c[k][1] = b[j][1];
//             c[k][2] = b[j][2];
//             j++;
//             k++;
//         }
//     }
//    
//     while (i <= termA)
//     {
//         c[k][0] = a[i][0];
//         c[k][1] = a[i][1];
//         c[k][2] = a[i][2];
//         i++;
//         k++;
//     }
//     while (j <= termB)
//     {
//         c[k][0] = b[j][0];
//         c[k][1] = b[j][1];
//         c[k][2] = b[j][2];
//         j++;
//         k++;
//     } 
//     c[0][2] = k-1;
// }
