#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

//HAVEL-HAKIMI
void verificareSecventaGradeGraf(vector<pair<int, int>> &secventaGrade) {

    ifstream f("..//graf.in");
    int nrNoduri;

    f >> nrNoduri;
    for (int i = 0; i < nrNoduri; i++) {
        int x;
        f >> x;
        secventaGrade.emplace_back(make_pair(x, i+1));
    }

    int sum = 0;
    for (pair<int, int> x : secventaGrade) {
        sum += x.first;
        if (x.first > nrNoduri - 1) {
            cout << "NU";
            return;
        }
    }
    if (sum % 2 != 0) {
        cout << "NU";
        return;
    }

    sort(secventaGrade.begin(), secventaGrade.end());

    while (!secventaGrade.empty() && secventaGrade[nrNoduri - 1].first != 0) {

        pair<int, int> nod = secventaGrade.back();
        secventaGrade.pop_back();
        nrNoduri--;

        for (int i = 1; i <= nod.first; i++) {
            secventaGrade[nrNoduri - i].first--;
            cout << nod.second << ' ' << secventaGrade[nrNoduri - i].second<<endl;
        }

        sort(secventaGrade.begin(), secventaGrade.end());

    }

}

int main() {

    vector<pair<int, int>> secventaGrade;

    verificareSecventaGradeGraf(secventaGrade);


}

