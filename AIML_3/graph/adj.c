#include<stdio.h>

// DFS
void dfs(int arr[10][10], int visited[10], int ver, int start){

    printf("%d  ", start);
    visited[start] = 1;
    for(int i = 0; i < ver; i++){
        if(arr[start][i] == 1 && visited[i] == 0){
            dfs(arr, visited, ver, i);
        }
    }
}

int main(){
    int vertex, edge, u, v;
    int arr[10][10] = {0};

    printf("Enter number of ver : ");
    scanf("%d", &vertex);
    printf("Enter number of edges : ");
    scanf("%d", &edge);

    for(int i = 0; i < edge; i++){
        printf("Enter the edge %d : ", i+1);
        scanf("%d %d", &u , &v);
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    printf("\nadjacency matrix : \n");
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    // BFS
    int queue[10];
    int front = 0;
    int rear = 0;
    int visited[10] = {0};
    int start;
    printf("\nEnter the start vetex : ");
    scanf("%d", &start);
    queue[rear] = start;
    rear++;
    visited[start] = 1;
    while(front < rear){
        int current = queue[front];
        front++;
        printf("%d  ", current);
        for(int i = 0; i < vertex; i++){
            if(arr[current][i] == 1 && visited[i] == 0){
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }

    }
    // dfs
    int visit[10] = {0};
    printf("\nDFS :-\n");
    dfs(arr, visit, vertex, start);
 }