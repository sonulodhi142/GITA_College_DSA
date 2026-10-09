#include<stdio.h>

// function for DFS traversal
void dfs(int arr[10][10],int visited[10], int ver, int start){

    printf("%d  ", start);

    visited[start] = 1;

    for(int i = 0; i<ver; i++){

        if (arr[start][i] == 1 && visited[i] == 0){
            dfs(arr, visited, ver, i);
        }

    }
}

int main(){
    int arr[10][10] = {0};
    int i, j, ver, edge, u, v;

    printf("Enter number of ver : ");
    scanf("%d", &ver);

    printf("Enter number of edge : ");
    scanf("%d", &edge);

    for( i = 0; i < edge; i++){
        printf("Enter the edge (u, v) : ");
        scanf("%d %d", &u, &v);

        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    printf("\nAdjacency matrix is : - \n\n");
    for(i = 0; i < ver; i++){
        printf("   %d  ", i);
    }
    printf("\n\n");
    for(i = 0; i < ver; i++){
        printf("%d  ", i);
        for(j = 0; j < ver; j++){
            printf("  %d  ", arr[i][j]);
        }
        printf("\n");
    }

    // BSF
    int queue[10];
    int rear = 0, front = 0;
    int visisted[10] = {0};
    int start;
    printf("Enter start ver : ");
    scanf("%d", &start);

    queue[rear++] = start;
    visisted[start] = 1;

    printf("\nBFS Traversal is :- \n");

    while(front < rear){
        int current = queue[front++];
        printf("%d  ", current);

        for(i = 0; i < ver; i++){
            if(arr[current][i] == 1 && visisted[i] == 0){
                queue[rear++] = i;

                visisted[i] = 1;
            }
        }
    }

    // dfs call
    int visit[10] = {0};
    printf("\n\nDFS traversal is : -\n\n");
    dfs(arr , visit, ver, start);
    
}