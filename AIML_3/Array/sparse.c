#include<stdio.h>

int main(){
    int max = 20, row, col, i, j;
    int sparse_matrix[max][max];
    printf("Enter number of rows :");
    scanf("%d", &row);
    printf("Enter number of cols :");
    scanf("%d", &col);

    printf("\nEnter %d X %d Matrix :\n", row, col);
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    printf("\nDisplay %d X %d Matrix :\n");
    for(i = 0; i<row; i++){
        for(j = 0; j < col; j++){
            printf("%d  ", sparse_matrix[i][j]);
        }
        printf("\n");
    }
    
    int Trip_rep[max][3];
    Trip_rep[0][0] = row;
    Trip_rep[0][1] = col;
    int k = 1;
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

    printf("\nDisplay Tiplet rep.....\n");
    for(i = 0; i < k; i++){
        printf("%d\t%d\t%d\t\n", Trip_rep[i][0],Trip_rep[i][1],Trip_rep[i][2]);
    }

    // triplet to sparse
    k = 1;
    printf("Trip_rep to sparse : \n");
    for(i = 0; i<row; i++){
        for(j = 0; j<col; j++){
            if(Trip_rep[k][0] == i && Trip_rep[k][1] == j){
                printf("%d  ", Trip_rep[k][2]);
                k++;
            }
            else{
                printf("%d  ", 0);
            }
        }
        printf("\n");
    }

    // transpose Triplet

    int tranpose[max][3];

    row = Trip_rep[0][0];
    col = Trip_rep[0][1];
    int nonZero = Trip_rep[0][2];

    // swap row to col
    tranpose[0][0] = col;
    tranpose[0][1] = row;
    tranpose[0][2] = nonZero;
    k = 1;
    for(i = 0; i < col; i++){
        for(j = 0; j <= nonZero; j++){
            if(Trip_rep[j][1] == i){
                tranpose[k][0] = Trip_rep[j][1];
                tranpose[k][1] = Trip_rep[j][0];
                tranpose[k][2] = Trip_rep[j][2];
                k++;
            }
        }
    }
    k = nonZero;
    // display transpose
    printf("\nDisplay tranpose rep.....\n");
    for(i = 0; i <= k; i++){
        printf("%d\t%d\t%d\t\n", tranpose[i][0],tranpose[i][1],tranpose[i][2]);
    }

}