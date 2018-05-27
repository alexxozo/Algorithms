#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// Variablile globale :(
// O(m * log n) KRUSKAL
int tata[100], h[100];

void Initializare(int u) {
    tata[u] = h[u] = 0;
}

int Reprez(int u) {
    while(tata[u] != 0) {
        u = tata[u];
    }
    return u;
}

void Reuniune(int u, int v) {
    int reprezU = Reprez(u);
    int reprezV = Reprez(v);

    if(h[reprezU] > h[reprezV]) {
        tata[reprezV] = reprezU;
    } else {
        tata[reprezU] = reprezV;
        if(reprezU == reprezV) {
            h[reprezV] = h[reprezV] + 1;
        }
    }
}

int main() {

    ifstream f("..//grafpond.in");

    typedef pair<int, int> pereche;
    typedef pair<pereche, int> nod;

    int nrNoduri, nrMuchii;
    vector<nod> graf;
    f >> nrNoduri >> nrMuchii;
    for (int i = 0; i < nrMuchii; i++) {
        int x, y, c;
        f >> x >> y >> c;
        graf.emplace_back(make_pair(make_pair(x, y), c));
    }


    for(int i = 1; i <= nrNoduri; i++) {
        Initializare(i);
    }

    sort(graf.begin(), graf.end(), [](const nod &n1, const nod &n2) { return n1.second > n2.second; });

    int muchiiAPCM = 0;

    while(!graf.empty()) {
        nod nodCurent = graf.back();
        graf.pop_back();

        if(Reprez(nodCurent.first.first) != Reprez(nodCurent.first.second)) {
            cout << nodCurent.first.first << ' ' << nodCurent.first.second << endl;
            Reuniune(nodCurent.first.first, nodCurent.first.second);

            muchiiAPCM++;
            if(muchiiAPCM == nrNoduri - 1) break;
        }
    }
}