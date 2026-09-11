#include<stdio.h>
#define max 20

// function to Create sparse matrix
void Create_sparse(int sparse[max][max], int row,int col){
    int i , j;
    printf("Enter value for %d X %d matrix : \n", row, col);
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &sparse[i][j]);
        }
    }
}

// function to display sparse matrix
void Display_sparse(int sparse[max][max], int row, int col){
    int i, j;
    printf("%d X %d matrix : \n", row, col);
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%d  ", sparse[i][j]);
        }
        printf("\n");
    }
}

// sparse to triplet representation
void Create_trip_rep(int sparse[max][max], int trip_rep[max][3], int row, int col){
    int i, j;
    trip_rep[0][0] = row;
    trip_rep[0][1] = col;
    int k = 1;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
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

// display triplet
void Display_trip_rep(int trip_rep[max][3]){
    int i, k = trip_rep[0][2];
    printf("Triplet representation\n");
    printf("row\tcol\tvalue\n");
    for(i = 0; i<=k; i++){
        printf("%d\t%d\t%d\n", trip_rep[i][0],trip_rep[i][1],trip_rep[i][2]);
    }
}

// function to transpose triplet representation
void create_transpose(int trip_rep[max][3], int transpose[max][3]){
    int row, col, i, j, k=1;
    row = trip_rep[0][0];
    col = trip_rep[0][1];
    int value = trip_rep[0][2];

    transpose[0][0] = col;
    transpose[0][1] = row;
    transpose[0][2] = value;

    for(i = 0; i<col; i++){
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

// addition of two triplet representation of sparse matrix
void trip_addition(int a[max][3], int b[max][3], int c[max][3]){
    
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1]){
        printf("\nAddition is not possible\n");
        return;
    }

    int valueA = a[0][2];
    int valueB = b[0][2];

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int i, j, k;
    i = j = k = 1;
    while(i <= valueA && j <= valueB){
        // addition logic
        if( a[i][0] == b[j][0] && a[i][1] == b[j][1] ){
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
    while (i <= valueA)
    {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
        i++;
    }
    while (j <= valueB)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        k++;
        j++;
    }
    c[0][2] = k-1;
}

int main(){
    int row, col, i, j;
    printf("Enter the rows : ");
    scanf("%d", &row);
    printf("Enter the cols : ");
    scanf("%d", &col);

    int a[max][max], b[max][max];
    int at[max][3], bt[max][3], ct[max][3];

    Create_sparse(a, row, col);
    Create_sparse(b, row, col);
    
    Create_trip_rep(a, at, row, col);
    Create_trip_rep(b, bt, row, col);

    trip_addition(at, bt, ct);
    Display_trip_rep(ct);

    // int sparse[max][max], trip_rep[max][3];

    // Create_sparse(sparse, row, col);
    // Display_sparse(sparse, row, col);

    // Create_trip_rep(sparse, trip_rep, row, col);
    // Display_trip_rep(trip_rep);

    // int transpose[max][3];

    // create_transpose(trip_rep, transpose);
    // Display_trip_rep(transpose);

    
    
    
    
    
}