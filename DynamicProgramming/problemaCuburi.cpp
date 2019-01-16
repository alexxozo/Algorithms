#include<iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>

using namespace std;

/*
 * Se consideră un șir de n cuburi colorate (n dat), pentru fiecare cub cunoscându-se lungimea laturii și
culoarea sa, codificată cu un număr de la 1 la p (p dat). Să se determine un turn de înălțime maximă în
care un cub nu poate fi așezat peste un cub de aceeași culoare sau cu latură mai mică sau egală cu a sa.
Afişaţi şi câte astfel de turnuri există. O(n2)
date.in date.out
7 3
8 3
10 2
9 2
10 1
8 1
5 2
6 2
OUT:
10 1
9 2
8 1
6 2
2
 */

bool dupaInaltimeCresc(const pair<int, int> a, const pair<int, int> b) {
    return a.first > b.first;
}

void celMaiInaltTurn(vector<pair<int, int>> cuburi) {
    vector<int> celMaiLungTurnPanaLa(cuburi.size(), 1);
    vector<int> pred(cuburi.size(), -1);

    sort(cuburi.begin(), cuburi.end(), dupaInaltimeCresc);

    // greedy varianta -> mai trb retinut si ultima inaltime
    int ultimaCuloare = cuburi[0].second;
    for (int m = 0; m < cuburi.size(); ++m) {
        if (cuburi[m].second != ultimaCuloare) {
            cout<<cuburi[m].first<<' '<<cuburi[m].second<<'\n';
            ultimaCuloare = cuburi[m].second;
        }
    }
    cout<<"----------\n";

    for (int i = 0; i < cuburi.size(); ++i) {
        int maxim = 0;
        for (int j = 0; j < i; ++j) {
            if (cuburi[j].first > cuburi[i].first && cuburi[i].second != cuburi[j].second && maxim < celMaiLungTurnPanaLa[j]) {
                maxim = celMaiLungTurnPanaLa[j];
                pred[i] = j;
            }
        }
        celMaiLungTurnPanaLa[i] = 1 + maxim;
    }
    for (int k = 0; k < cuburi.size(); ++k) {
        cout<<celMaiLungTurnPanaLa[k]<<' ';
    }
    cout<<endl;
    for (int k = 0; k < cuburi.size(); ++k) {
        cout << pred[k] << ' ';
    }
    cout<<"\nUnul dintre turnurile de lungime maxima este: ";
    int pozStart = -1;
    int maxim = INT_MIN;
    for (int l = 0; l < cuburi.size(); ++l) {
        if (maxim < celMaiLungTurnPanaLa[l]) {
            maxim = celMaiLungTurnPanaLa[l];
            pozStart = l;
        }
    }
    while (pred[pozStart] != -1) {
        cout<<cuburi[pozStart].first<<' '<<cuburi[pozStart].second<<'\n';
        pozStart = pred[pozStart];
    }
    cout<<cuburi[pozStart].first<<' '<<cuburi[pozStart].second<<'\n';
}

int main() {
    fstream f("E:\\FACULTATE\\SEM1\\TAP\\listaProbleme\\PD\\cuburiData.txt");
    vector<pair<int, int>> cuburi;
    while (!f.eof()) {
        pair<int, int> p;
        f >> p.first >> p.second;
        cuburi.push_back(p);
    }
    celMaiInaltTurn(cuburi);
}

