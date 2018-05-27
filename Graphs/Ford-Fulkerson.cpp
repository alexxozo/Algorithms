#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

/// geeksforgeeks implementation V = 6 number of vertices
#define V 6

bool bfs(int residualGraf[V][V], int start, int final, int parinte[]) {
    bool viz[V];
    memset(viz, 0, sizeof(viz));

    queue<int> q;
    q.push(start);
    viz[start] = true;
    parinte[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        //Bagam toti vecinii care au val reziduala mai mare ca 0 si
        //nu au mai fost vizitati
        for (int v = 0; v < V; v++)
            if (!viz[v] && residualGraf[u][v] > 0) {
                parinte[v] = u;
                viz[v] = true;
                q.push(v);
            }
    }

    return viz[final];

}

int fordFulkerson(int graf[V][V], int start, int final) {
    int u, v;
    int residualGraf[V][V];
    //Pentru prima iteriatie graful rezidual coincide cu cel original
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            residualGraf[u][v] = graf[u][v];
        }
    }

    int parinte[V];
    int max_flow = 0;

    //Cat timp mai exista drumuri pe car putem baga flux
    while (bfs(residualGraf, start, final, parinte)) {

        int path_flow = INT_MAX;
        //Parcurgem drumul de la final la inceput si aflam fluxul minim
        for (v = final; v != start; v = parinte[v]) {
            u = parinte[v];
            path_flow = min(path_flow, residualGraf[u][v]);
        }

        //Actualizam graful rezidual scazand fluxul minim si adaugandu-l in sens invers
        for (v = final; v != start; v = parinte[v]) {
            u = parinte[v];
            residualGraf[u][v] -= path_flow;
            residualGraf[v][u] += path_flow;
        }

        //Adaugam fluxum minim al drumului la fluxul maxim al grafului
        max_flow += path_flow;
    }

    return max_flow;

}

int main() {
    ifstream f("..//graf.in");
    int nrNoduri, nrMuchii, nodFinal, nodStart;

    f >> nrNoduri >> nodStart >> nodFinal >> nrMuchii;
    int graf[V][V];

    //Init cu 0
    memset(graf, 0, sizeof(graf));

    //Citire graf
    for (int i = 0; i < nrMuchii; i++) {
        int x, y, c;
        f >> x >> y >> c;
        graf[x][y] = c;
    }

    //Afisare graf
    for (int i = 0; i < nrNoduri; i++) {
        for (int j = 0; j < nrNoduri; j++) {
            cout << graf[i][j] << ' ';
        }
        cout << endl;
    }

    cout << fordFulkerson(graf, 0, 5);
}