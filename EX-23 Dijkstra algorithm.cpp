#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int minDistance(int distances[], int visited[], int numNodes) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && distances[i] < min) {
            min = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printPath(int parent[], int target) {
    if (parent[target] == -1) {
        printf("%d ", target);
        return;
    }

    printPath(parent, parent[target]);
    printf("%d ", target);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int source) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    distances[source] = 0;

    for (int i = 0; i < numNodes - 1; i++) {
        int u = minDistance(distances, visited, numNodes);
        visited[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t%d\t\t", i, distances[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, numNodes, source);

    return 0;
}

