#include <iostream>

#define V 4

void printSolution(int dist[][V]) {
    printf("Following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graf[][V]) {

    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graf[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}


int main() {


    int graph[V][V] = {{0,   5,  9999, 10}, {9999, 0,   3, 9999}, {9999, 9999, 0,   1}, {9999, 9999, 9999, 0}};

    floydWarshall(graph);

    return 0;
}