#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int minKey(int key[], int mstSet[], int numNodes) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 0; i < numNodes; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void printMST(int parent[], int graph[MAX_NODES][MAX_NODES], int numNodes) {
    printf("Edge\tWeight\n");
    for (int i = 1; i < numNodes; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    int mstSet[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;         
    parent[0] = -1;     

    for (int count = 0; count < numNodes - 1; count++) {
        int u = minKey(key, mstSet, numNodes);
        mstSet[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, numNodes);
}

int main() {
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (0 for no edge, weight for edge):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, numNodes);

    return 0;
}

