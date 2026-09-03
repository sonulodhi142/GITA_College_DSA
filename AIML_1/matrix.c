#include<stdio.h>
# define max 20

int create_matrix(int matrix[max][max], int row, int col){
    printf("\nEnter %d X %d Matrix : \n", row, col);
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

int Display_matrix(int matrix[max][max], int row, int col){
    printf("\n%d X %d Matrix : \n", row, col);
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Create_triplet_rep(int matrix[max][max], int trip[max][3], int row, int col){
    int i, j, k=1;
    trip[0][0] = row;
    trip[0][1] = col;
    for(i = 0; i<row; i++){
        for(j = 0; j<col; j++){
            if(matrix[i][j] != 0){
                trip[k][0] = i;
                trip[k][1] = k;
                trip[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    trip[0][2] = k-1;
}



int main(){
    int matrix[max][max], row, col;

    printf("Enter rows : ");
    scanf("%d", &row);
    printf("Enter col : ");
    scanf("%d", &col);

    create_matrix(matrix, row, col);
    Display_matrix(matrix, row, col);
}