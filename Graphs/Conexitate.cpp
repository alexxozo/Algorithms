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

void DFSUtil(int nod, bool viz[], GrafAdiacenta graf, int &noduriConexe) {

    viz[nod] = true;
    noduriConexe++;

    for(int x : graf.lista[nod]) {
        if(!viz[x]) {
            DFSUtil(x, viz, graf, noduriConexe);
        }
    }

}

void verificareConexDFS(GrafAdiacenta graf) {
    bool viz[graf.nrNoduri + 1];
    int noduriConexe = 0;
    memset(viz, false, sizeof(viz));

    DFSUtil(1, viz, graf, noduriConexe);

    if(noduriConexe != graf.nrNoduri) cout<<"Graful nu este conex!";
    else cout<<"Graful este conex!";
}

void verificareConexBFS(GrafAdiacenta graf) {

    queue<int> Q;
    bool viz[graf.nrNoduri + 1];
    int noduriConexe = 1;
    memset(viz, false, sizeof(viz));

    Q.push(1);
    viz[1] = true;

    while(!Q.empty()) {
        int nod = Q.front();
        Q.pop();

        for(int x : graf.lista[nod]) {
            if(!viz[x]) {
                Q.push(x);
                viz[x] = true;
                noduriConexe++;
                //cout<<x<<" ";
            }
        }
    }

    if(noduriConexe != graf.nrNoduri) cout<<"Graful nu este conex!";
    else cout<<"Graful este conex!";
}

int main()
{

    GrafAdiacenta graf;

    citireGraf("..//muchii.in", graf);

    verificareConexBFS(graf);

    /*for(int i = 1; i < graf.nrMuchii; i++) {
        cout<<i<<" : ";
        for(int x : graf.lista[i]) {
            cout<<x<<' ';
        }
        cout<<endl;
    }*/

}
