#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};
struct Graph {
    int numNodes;
    int** adjList;
};

struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;

    graph->adjList = (int**)malloc(numNodes * sizeof(int*));
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjList[src] = (int*)realloc(graph->adjList[src], sizeof(int));
    graph->adjList[src][0] = dest;
}

void BFS(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    queue->items[++queue->rear] = startNode;
    visited[startNode] = 1;

    while (queue->front < queue->rear) {
        int currentNode = queue->items[++queue->front];
        printf("%d ", currentNode);

        for (int i = 0; graph->adjList[currentNode][i] != 0; i++) {
            int adjNode = graph->adjList[currentNode][i];
            if (!visited[adjNode]) {
                queue->items[++queue->rear] = adjNode;
                visited[adjNode] = 1;
            }
        }
    }

    free(queue);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    struct Graph* graph = createGraph(numNodes);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    BFS(graph, startNode);

    return 0;
}

