#include<stdio.h>

int main(){
    int i, j, ver, edge, u, v;
    int arr[10][10] = {0};
    printf("Enter number of ver : ");
    scanf("%d", &ver);
    printf("Enter number of edge : ");
    scanf("%d", &edge);

    for(i = 0; i < edge; i++){
        printf("Enter edge (u, v) : ");
        scanf("%d %d", &u, &v);

        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    printf("\nAdjecancy matrix is :-\n\n");
    for(i = 0; i < ver; i++){
        for(j = 0; j < ver; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    // BFS
    int visited[10] = {0};
    int queue[10];
    int front=0, rear= 0;
    int start;
    printf("Enter the start ver : ");
    scanf("%d", &start);

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    printf("\nBFS Traversal :- \n");
    while(front < rear){
        int current = queue[front];
        front++;
        printf("%d  ", current);
        for(i = 0; i < ver; i++){
            if(arr[current][i] == 1 && visited[i] == 0){
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}