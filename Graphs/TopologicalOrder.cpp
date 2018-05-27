#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct GrafAdiacenta {
    vector<vector<int>> lista;
    int nrNoduri, nrMuchii;
};

void citireGrafOrientat(char *numeFisier, GrafAdiacenta &graf) {
    ifstream f(numeFisier);

    f >> graf.nrNoduri >> graf.nrMuchii;
    graf.lista.resize(graf.nrNoduri + 1);
    for (int i = 0; i < graf.nrMuchii; i++) {
        int x, y;
        f >> x >> y;
        graf.lista[x].emplace_back(y);
    }
}

void topologicalOrderUtil(int nod, GrafAdiacenta graf, vector<int> &stack, bool viz[]) {

    // Marcam nodul ca vizitat
    viz[nod] = true;

    // Pentru fiecare vecin al sau
    for (int x : graf.lista[nod]) {
        // Daca nu a fost vizitat il vizitam
        if (!viz[x]) {
            topologicalOrderUtil(x, graf, stack, viz);
        }
    }

    // Cand am ajuns la un capat incepem sa bagam nodurile in stack in ordine inversa
    stack.emplace_back(nod);

}

void topologicalOrder(GrafAdiacenta graf) {

    vector<int> stack;
    bool viz[graf.nrNoduri + 1];

    memset(viz, false, sizeof(viz));

    // Plecam cu DFS ul din fiecare nod al grafului
    for (int v = 1; v <= graf.nrNoduri; v++) {
        if (!viz[v]) {
            topologicalOrderUtil(v, graf, stack, viz);
        }
    }

    while (!stack.empty()) {
        cout << stack.back() << ' ';
        stack.pop_back();
    }

}

int main() {

    GrafAdiacenta graf;

    citireGrafOrientat("..//top_order.in", graf);

    //cout << graf.lista[1][1];

    topologicalOrder(graf);

}

