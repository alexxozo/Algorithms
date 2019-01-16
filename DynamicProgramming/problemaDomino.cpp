#include<iostream>
#include <vector>
#include<map>
#include <fstream>

using namespace std;

/*
Se consideră un şir de n piese de domino. O piesă de domino are formă dreptunghiulară şi are înscrisă pe
ea două numere. Conform regulilor la domino, un lanţ de piese este un subşir al şirului de
piese iniţial constituit din piese care respectă următoarea condiţie: pentru oricare două piese consecutive
din lanţ, al doilea număr înscris pe prima din cele două piese coincide cu primul număr înscris pe cea de
a doua piesă (piesele nu se pot roti). Se citesc din fișierul date.in un număr natural n și un șir de n
perechi ordonate de numere reprezentând piese de domino.
a) Să se determine un lanţ de lungime maximă care se poate obţine cu piesele din şirul dat (adică un cel
mai lung subșir de perechi cu proprietatea că, pentru oricare două perechi consecutive din subșir, ultimul
număr din prima pereche coincide cu primul număr din cea de a doua pereche).
b) Determinați câte astfel de subșiruri de lungime maximă există. O(n2
) (2p)
date.in date.out (un exemplu, soluţia nu este unică)
7
1 8
1 5
5 3
5 2
4 8
2 4
2 3
OUT:
1 5
5 2
2 4
2
 */

void determinareLantDeLungimeMaxima(vector<pair<int, int>> domino) {
    map<int, int> lungimeaMaximaAUnuiLantCareSeTerminaPe;
    map<int, int> pred, pozitie;
    // nu cred ca era necesar
    for (auto pair : domino) {
        lungimeaMaximaAUnuiLantCareSeTerminaPe[pair.first] = 0;
        lungimeaMaximaAUnuiLantCareSeTerminaPe[pair.second] = 0;
    }

    for (int i = 0; i < domino.size(); i++) {
        if (lungimeaMaximaAUnuiLantCareSeTerminaPe[domino[i].first] + 1 > lungimeaMaximaAUnuiLantCareSeTerminaPe[domino[i].second]) {
            lungimeaMaximaAUnuiLantCareSeTerminaPe[domino[i].second] = lungimeaMaximaAUnuiLantCareSeTerminaPe[domino[i].first] + 1;
            pred[domino[i].second] = pozitie[domino[i].first];
            pozitie[domino[i].second] = i;
        }
    }

    for (auto x : lungimeaMaximaAUnuiLantCareSeTerminaPe) {
        cout<<x.first<<' '<<x.second<<'\n';
    }

    int maxim = 0;
    for (auto x : lungimeaMaximaAUnuiLantCareSeTerminaPe) {
        if (maxim < x.second) {
            maxim = x.second;
        }
    }

    for (auto x : lungimeaMaximaAUnuiLantCareSeTerminaPe) {
        if (x.second == maxim) {
            pair<int, int> currentDomino = domino[pozitie[x.first]];
            int currentPred = pred[currentDomino.second];
            while (pred[currentDomino.second]) {
                cout << '(' << currentDomino.first << ',' << currentDomino.second <<")\n";
                currentDomino = domino[currentPred];
                currentPred = pred[currentDomino.first];
            }
            cout << '(' << currentDomino.first << ',' << currentDomino.second <<")\n";
            cout<<"\n---------------";
        }
    }
}

int main() {
    ifstream f("E:\\FACULTATE\\SEM1\\TAP\\listaProbleme\\PD\\dominoData.txt");
    int n;
    vector<pair<int, int>> domino;
    f >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        f >> p.first >> p.second;
        domino.push_back(p);
    }
    determinareLantDeLungimeMaxima(domino);
}
