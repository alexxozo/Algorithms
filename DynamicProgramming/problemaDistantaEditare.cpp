/*
    explicatia detaliata este in caiet
    inteleasa de la baiatul asta -> https://www.youtube.com/watch?v=We3YDTzNXEk
    stanga stergere, sus adaugare si diag modif

    matricea va arata asa
      a b c d
    0 1 2 3 4
  z 1
  x 2
  y 3
 */
#include<iostream>
#include <vector>

using namespace std;

void distantaLevensthein(string cuvant1, string cuvant2) {
    vector<vector<int>> nrMinimDeModificariPentruATransformaSirul1In2(cuvant2.size() + 1);
    for (int i = 0; i < cuvant2.size() + 1; ++i) {
        nrMinimDeModificariPentruATransformaSirul1In2[i].resize(cuvant1.size() + 1);
    }

    for (int j = 1; j < cuvant1.size() + 1; ++j) {
        nrMinimDeModificariPentruATransformaSirul1In2[0][j] = j;
    }

    for (int j = 1; j < cuvant2.size() + 1; ++j) {
        nrMinimDeModificariPentruATransformaSirul1In2[j][0] = j;
    }

    for (int i = 1; i < nrMinimDeModificariPentruATransformaSirul1In2.size(); i++) {
        for (int j = 1; j < nrMinimDeModificariPentruATransformaSirul1In2[i].size(); j++) {
            if (cuvant1[i - 1] == cuvant2[j - 1]) {
                // daca ultima litera din c1 e egala cu ultima din c2 atunci luam val de pe diagonala ceea ce rep faptul ca nu avem nimic de facut
                nrMinimDeModificariPentruATransformaSirul1In2[i][j] = nrMinimDeModificariPentruATransformaSirul1In2[i - 1][j - 1];
            } else {
                nrMinimDeModificariPentruATransformaSirul1In2[i][j] = 1 + min(nrMinimDeModificariPentruATransformaSirul1In2[i - 1][j - 1], min(nrMinimDeModificariPentruATransformaSirul1In2[i - 1][j], nrMinimDeModificariPentruATransformaSirul1In2[i][j-1]));
            }
        }
    }

    for (int i = 0; i < nrMinimDeModificariPentruATransformaSirul1In2.size(); i++) {
        for (int j = 0; j < nrMinimDeModificariPentruATransformaSirul1In2[i].size(); j++) {
            cout << nrMinimDeModificariPentruATransformaSirul1In2[i][j] << ' ';
        }
        cout<<endl;
    }
}

int main() {
    distantaLevensthein("abcdef", "azced");
}