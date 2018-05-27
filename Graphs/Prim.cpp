#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <list>
#include <set>
using namespace std;

int main() {

    ifstream f("..//date.in");
    vector<int>d, pred;
    vector<bool>viz;
    vector<pair<int, int>> E; /// memoram aici muchiile APCM ului
    vector<list<pair<int, int>>>L; /// lista de vecini pt fiecare nod
    int n, m;

    // Citire ------------------
    f>>n>>m;

    // Distantele vor fii 1000 la inceput
    d.resize(n + 1, 1000);
    pred.resize(n + 1);
    L.resize(n + 1);
    viz.resize(n + 1, false);

    for(int i = 0; i < m; i++) {
        int nod1, nod2, cost;
        f>>nod1>>nod2;
        f>>cost;
        L[nod1].emplace_back(make_pair(cost, nod2));
        L[nod2].emplace_back(make_pair(cost, nod1));
    }

    // -------------------------

    // De unde plecam
    int nodStart = 5;
    //cin>>nodStart;

    // Distanta initiala si predecesorul
    d[nodStart] = 0;
    pred[nodStart] = 0;

    set<pair<int, int>>Q; /// folosit ca un priority_queue
    // first e costul si second e nodul
    Q.insert(make_pair(0, nodStart));

    while(!Q.empty()) {
        /// Pop la primul element
        pair<int, int> p = (*Q.begin());
        Q.erase(Q.begin());

        // Daca nu este vizitat nodul si nu e cumva nodul de start atunci introducem in lista de muchii (nod, tata[nod])
        int nod = p.second;
        int cost = p.first;
        if(!viz[nod] && nod != nodStart) {
            viz[nod] = true;
            E.emplace_back(make_pair(nod, pred[nod]));
        }

        for(pair<int, int> x : L[nod]) {
            /// Daca nodul vecin cu nodul curent nu a mai fost vizitat
            if(!viz[x.second]) {
                /// Daca costul curent de pe pozitia vecinului este mai mare decat cel gasit
                if(d[x.second] > x.first) {
                    d[x.second] = x.first;
                    pred[x.second] = nod;
                    Q.insert(x);
                }
            }
        }
    }

    for(pair<int, int> x : E) {
        cout<<x.first<<'-'<<x.second<<endl;
    }


}