#include <stdio.h>

#define INF 2147483647

int V;

void floydWarshall(int dist[][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Verificăm dacă drumul prin k este mai scurt
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

   for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%s ", "INF");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Cate noduri?\n");
    scanf("%d", &V);

    int graph[V][V];

    printf("Matrice de ponderi:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == INF || i == j) {
                graph[i][j] = (i == j) ? 0 : INF;
            }
        }
    }
    printf("\n");
    floydWarshall(graph);
    return 0;
}