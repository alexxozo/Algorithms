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

void citireGraf(char *numeFisier, GrafAdiacenta &graf) {
    ifstream f(numeFisier);

    f >> graf.nrNoduri >> graf.nrMuchii;
    graf.lista.resize(graf.nrNoduri + 1);
    for(int i = 0; i < graf.nrMuchii; i++) {
        int x, y;
        f >> x >> y;
        graf.lista[x].emplace_back(y);
        graf.lista[y].emplace_back(x);
    }
}

bool verificareCicluUtil(GrafAdiacenta graf, bool viz[], int nod, int p[], int parinte) {
    // Marcam nodul ca vizitat in DFS
    viz[nod] = true;

    // Pentru fiecare vecin al lui
    for(int x : graf.lista[nod]) {
        // Daca vecinul nu a fost vizitat
        if(!viz[x]) {
            // Setam parintele lui ca fiind nodul curent
            p[x] = nod;
            // Daca continuam DFS pe el si ne da ca exista un ciclu atunci returnam true
            //if()
                return true;
        } else if(x != parinte) {
            // Daca vecinul a fost vizitat si este difereit de parinte inseamna ca am gasit un ciclu
            p[x] = nod;
            int nodStart = x;
            cout<<x<<' ';
            x = p[x];
            while(x != nodStart) {
                cout<<x<<' ';
                x = p[x];
            }
            return true;
        }
    }
    return false;

}

bool verificareCiclu(GrafAdiacenta graf) {

    bool viz[graf.nrNoduri + 1];
    int p[graf.nrNoduri + 1];

    memset(viz, false, sizeof(viz));
    memset(p, false, sizeof(p));

    // Facem DFS din fiecare nod, poate nu e graful conex sau cv
    for(int nod = 1; nod <= graf.nrNoduri; nod++) {
        if(!viz[nod]) {
            if(verificareCicluUtil(graf, viz, nod, p, -1))
            {
               return true;
            }
        }
    }
    return false;
}

int main()
{

    GrafAdiacenta graf;

    citireGraf("..//muchii_neorientat.in", graf);

    /*for(int i = 1; i < graf.nrMuchii; i++) {
        cout<<i<<" : ";
        for(int x : graf.lista[i]) {
            cout<<x<<' ';
        }
        cout<<endl;
    }*/

    cout<<verificareCiclu(graf);

}


