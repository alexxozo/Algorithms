#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// Se poate optimiza

void verificareSecventaGradeArbore(vector<pair<int, int>> &secventaGrade) {

    ifstream f("..//date.in");
    int nrNoduri;

    f >> nrNoduri;
    for (int i = 0; i < nrNoduri; i++) {
        int x;
        f >> x;
        // Stanga = grad, Dreapta = indice nod
        secventaGrade.emplace_back(make_pair(x, i+1));
    }

    // Prima verificare
    int sum = 0;
    for(pair<int, int> x : secventaGrade) {
        sum += x.first;
    }
    if(sum != 2 * (nrNoduri - 1)) {
        cout<<"NU";
        return ;
    }

    // A doua verificare si construirea
    bool gradeMaiMariCaUnu = true;
    while(gradeMaiMariCaUnu) {
        gradeMaiMariCaUnu = false;
        sort(secventaGrade.begin(), secventaGrade.end(), [](const pair<int, int> g1, const pair<int, int> g2) { return g1.first > g2.first; });

        for(pair<int, int> x : secventaGrade) {
            if(x.first > 1) {
                gradeMaiMariCaUnu = true;
                break;
            }
        }

        int nod1, nod2;
        nod1 = secventaGrade.back().second;
        secventaGrade.pop_back();

        for(int i = 0; i < secventaGrade.size(); i++) {
            if(secventaGrade[i].first > 1) {
                nod2 = secventaGrade[i].second;
                secventaGrade[i].first--;
                break;
            }
        }

        cout<<nod1<<' '<<nod2<<endl;
    }

    if(secventaGrade.size() == 2)
        cout<<secventaGrade.back().second<<' '<<secventaGrade.front().second;

}

int main() {

    vector<pair<int, int>> secventaGrade;

    verificareSecventaGradeArbore(secventaGrade);


}