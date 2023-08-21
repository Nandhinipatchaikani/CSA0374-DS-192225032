#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
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
void DFSRecursive(struct Graph* graph, int currentNode, int visited[]) {
    printf("%d ", currentNode);
    visited[currentNode] = 1;

    for (int i = 0; graph->adjList[currentNode][i] != 0; i++) {
        int adjNode = graph->adjList[currentNode][i];
        if (!visited[adjNode]) {
            DFSRecursive(graph, adjNode, visited);
        }
    }
}
void DFS(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};
    DFSRecursive(graph, startNode, visited);
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
    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    DFS(graph, startNode);

    return 0;
}

