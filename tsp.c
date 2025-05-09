
#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;  // Number of cities
int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX]; // To track visited cities
int min_cost = INT_MAX; // Stores minimum cost

// Function to find the minimum cost path using backtracking
void tsp(int current, int count, int cost, int start) {
    if (count == n && graph[current][start]) {
        if (cost + graph[current][start] < min_cost) {
            min_cost = cost + graph[current][start];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current][i]) {
            visited[i] = 1;
            tsp(i, count + 1, cost + graph[current][i], start);
            visited[i] = 0;  // Backtrack
        }
    }
}

// Main function
int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (enter 0 for no direct path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[0] = 1; // Start from the first city
    tsp(0, 1, 0, 0);

    printf("Minimum travel cost: %d\n", min_cost);

    return 0;
}
