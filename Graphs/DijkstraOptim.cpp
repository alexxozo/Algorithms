#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>
using namespace std;

// Dijkstra optim
// O(E * logV) = O(logV)

void rezolvareDijkstra(char *numeFisier) {

    ifstream f(numeFisier);
    int nrNoduri, nrMuchii;
    vector<vector<pair<int, int>>> listaAdicenta;

    f>>nrNoduri>>nrMuchii;
    listaAdicenta.resize(nrNoduri + 1);
    for(int i = 0; i < nrMuchii; i++) {
        int x, y, c;
        f>>x>>y>>c;
        listaAdicenta[x].emplace_back(make_pair(y, c));
    }

    int distanta[nrNoduri + 1], tata[nrNoduri + 1];

    memset(distanta, 10, sizeof(distanta)); // aparent aici nu pune 10 pune o valoare ft mare
    memset(tata, 0, sizeof(tata));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    PQ.push(make_pair(0, 1));
    distanta[1] = 0;
    tata[1] = 0;

    while(!PQ.empty()) {

        pair<int, int> minVertex = PQ.top();
        PQ.pop();

        for(pair<int, int> x : listaAdicenta[minVertex.second]) {
            int nod_x = x.first;
            int cost_x = x.second;
            if(distanta[minVertex.second] + cost_x < distanta[nod_x]) {
                distanta[nod_x] = distanta[minVertex.second] + cost_x;
                tata[nod_x] = minVertex.second;
                PQ.push(make_pair(distanta[nod_x], nod_x));
            }
        }

    }

    // ex
    /* cout<<"Cel mai scurt drum de la 1 la 5 este : ";
     int x = tata[5];
     cout<<"5 ";
     while(x != 1) {
         cout<<x<<' ';
         x = tata[x];
     }
     cout<<"1";*/
    for(int i = 1; i <=nrNoduri; i++) {
        cout<<distanta[i]<<' ';
    }

}

int main() {

    rezolvareDijkstra("..//date.in");

}

