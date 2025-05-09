#include <stdio.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int vertices, edges;
    Edge edge[MAX];
} Graph;

// Function to find set of an element (uses path compression)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);  // Path compression
}

// Function to perform union of two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Function to sort edges by weight (Bubble Sort)
void sortEdges(Graph* graph) {
    for (int i = 0; i < graph->edges - 1; i++) {
        for (int j = 0; j < graph->edges - i - 1; j++) {
            if (graph->edge[j].weight > graph->edge[j + 1].weight) {
                Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }
}

// Function to implement Kruskal's Algorithm
void kruskalMST(Graph* graph) {
    Edge result[MAX]; // Stores the MST
    int parent[MAX], rank[MAX];
    int e = 0, i = 0;

    sortEdges(graph); // Step 1: Sort all edges

    for (int v = 0; v < graph->vertices; v++) {
        parent[v] = v; // Initialize each vertex as its own parent
        rank[v] = 0;
    }

    while (e < graph->vertices - 1 && i < graph->edges) {
        Edge nextEdge = graph->edge[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) { // Check if it forms a cycle
            result[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

// Main function
int main() {
    Graph graph;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &graph.vertices, &graph.edges);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < graph.edges; i++)
        scanf("%d %d %d", &graph.edge[i].src, &graph.edge[i].dest, &graph.edge[i].weight);

    kruskalMST(&graph);

    return 0;
}
