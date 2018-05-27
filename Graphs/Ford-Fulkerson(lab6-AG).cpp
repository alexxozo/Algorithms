#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

bool bfs(int marimeGraf, int grafRezidual[100][100], int parinte[], int nodStart, int nodFinal) {
    bool viz[marimeGraf + 1];
    memset(viz, 0, sizeof(viz));

    queue<int> q;
    q.push(nodStart);
    viz[nodStart] = true;
    parinte[nodStart] = -1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int i = 1; i < marimeGraf + 1; i++) {
            if(grafRezidual[v][i] > 0 && !viz[i]) {
                q.push(i);
                parinte[i] = v;
                viz[i] = true;
            }
        }
    }

    return viz[nodFinal];
}

int FordFulkerson(int marimeGraf, int grafRezidual[100][100], int nodStart, int nodFinal) {

    int parinte[100];
    int flux_drum = INT_MAX, flux_maxim = 0;

    while(bfs(marimeGraf, grafRezidual, parinte, nodStart, nodFinal)) {
        // Pentru drumul de la final la start
        for(int v = nodFinal; v != nodStart; v = parinte[v]) {
            //cout<<v<<' ';
            int u = parinte[v];
            flux_drum = min(flux_drum, grafRezidual[u][v]);
        }
        //cout<<flux_drum<<endl;

        for (int v = nodFinal; v != nodStart; v = parinte[v]) {
            int u = parinte[v];
            grafRezidual[u][v] -= flux_drum;
            grafRezidual[v][u] += flux_drum;
        }

        /*for (int i = 0; i < marimeGraf + 1; i++) {
            for (int j = 0; j < marimeGraf + 1; j++) {
                cout<<grafRezidual[i][j]<<' ';
            }
            cout<<endl;
        }*/

        flux_maxim += flux_drum;
    }

    return flux_maxim;

}

int main() {
    ifstream f("..//retea.in");
    int nrNoduri, nrMuchii, nodFinal, nodStart;

    // F = fluxuri, C = capacitati
    f >> nrNoduri >> nodStart >> nodFinal >> nrMuchii;
    int F[nrNoduri + 1][nrNoduri + 1], C[nrNoduri + 1][nrNoduri + 1];
    memset(F, 0, sizeof(F));
    memset(C, 0, sizeof(C));

    for(int i = 0; i < nrMuchii; i++) {
        int x, y, fl, c;
        f >> x >> y >> c >> fl;
        F[x][y] = fl;
        C[x][y] = c;
    }

    // a - sa se verifice daca fluxul dat este corect
    bool ok = true;
    for(int i = 1; i <= nrNoduri; i++) {
        // Verificam marginirea
        for(int j = 1; j <= nrNoduri; j++) {
            if (F[i][j] > C[i][j]) ok = false;
        }
        // Verificam conservarea
        if(i != nodStart && i != nodFinal) {
            int sumaIesire = 0, sumaIntrare = 0;
            for (int k = 1; k <= nrNoduri; k++)
                sumaIesire += F[i][k];
            for (int k = 1; k <= nrNoduri; k++)
                sumaIntrare += F[k][i];
            if (sumaIesire != sumaIntrare) ok = false;
        }
    }
    if(ok == true) cout<<"DA "; else cout<<"NU ";

    // b - sa se determine un flux maxim in retea pornind de la acest flux
    int grafRezidual[100][100];

    for (int i = 1; i < nrNoduri + 1; i++) {
        for (int j = 1; j < nrNoduri + 1; j++) {
            if(C[i][j] == F[i][j] && C[i][j] != 0)  {
                grafRezidual[j][i] = C[i][j];
                cout<<"("<<j<<","<<i<<", "<<C[i][j]<<")";
                cout<<grafRezidual[j][i];
            }
             else {
                grafRezidual[i][j] = C[i][j] - F[i][j];
            }
        }
    }

    for (int i = 1; i < nrNoduri + 1; i++) {
        for (int j = 1; j < nrNoduri + 1; j++) {
            cout<<grafRezidual[i][j]<<' ';
        }
        cout<<endl;
    }

    cout << FordFulkerson(nrNoduri, grafRezidual, nodStart, nodFinal);



}