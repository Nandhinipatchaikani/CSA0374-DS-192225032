#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int parent[MAX_NODES];
    int rank[MAX_NODES];
};

struct DisjointSet* createDisjointSet(int numNodes) {
    struct DisjointSet* ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    for (int i = 0; i < numNodes; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

int findRoot(struct DisjointSet* ds, int node) {
    if (ds->parent[node] != node)
        ds->parent[node] = findRoot(ds, ds->parent[node]);
    return ds->parent[node];
}

void unionSets(struct DisjointSet* ds, int node1, int node2) {
    int root1 = findRoot(ds, node1);
    int root2 = findRoot(ds, node2);

    if (ds->rank[root1] < ds->rank[root2])
        ds->parent[root1] = root2;
    else if (ds->rank[root1] > ds->rank[root2])
        ds->parent[root2] = root1;
    else {
        ds->parent[root2] = root1;
        ds->rank[root1]++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Edge edges[], int numEdges, int numNodes) {
    struct DisjointSet* ds = createDisjointSet(numNodes);
    struct Edge result[MAX_NODES]; 

    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int resultIndex = 0;
    for (int i = 0; i < numEdges; i++) {
        int srcRoot = findRoot(ds, edges[i].src);
        int destRoot = findRoot(ds, edges[i].dest);

        if (srcRoot != destRoot) {
            result[resultIndex++] = edges[i];
            unionSets(ds, srcRoot, destRoot);
        }
    }

    printf("Edge\tWeight\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d\t%d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(ds);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    struct Edge edges[MAX_EDGES];
    printf("Enter the edges (src dest weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, numEdges, numNodes);

    return 0;
}

