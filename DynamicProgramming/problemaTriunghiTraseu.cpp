/*
 * Se consider˘a un triunghi de numere naturale nenule t cu n linii. S˘a se
determine cea mai mare sum˘a pe care o putem forma dac˘a ne deplas˘am ˆın
triunghi ¸si adun˘am numerele din celulele de pe traseu, regulile de deplasare
fiind urm˘atoarele:
Pornim de la num˘arul de pe prima linie;
Din celula (i,j) putem merge doar ˆın (i+1,j) sau (i+1,j+1).
Traseul se opre¸ste pe oricare dintre celulele ultimei linii.
1
3 2
7 6 9
0 5 8 4
 */

#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

void calculTraseuMaxim(vector<vector<int>> triunghi) {
    vector<vector<int>> sumaMaximaPePozitia(triunghi.size());
    for (int j = 0; j < triunghi.size(); ++j) {
        sumaMaximaPePozitia[j].resize(triunghi.size());
    }

    for (int l = 0; l < triunghi.size(); ++l) {
        for (int i = 0; i < triunghi.size(); ++i) {
            sumaMaximaPePozitia[l][i] = triunghi[l][i];
        }
    }

    //sumaMaximaPePozitia[0][0] = triunghi[0][0];
    for (int i = 1; i < triunghi.size(); ++i) {
        for (int j = 0; j < i + 1; ++j) {
            //int maxim = sumaMaximaPePozitia[i][j];
            if (j == i)
                sumaMaximaPePozitia[i][j] += sumaMaximaPePozitia[i-1][j-1];
            else if (j == 0)
                sumaMaximaPePozitia[i][j] += sumaMaximaPePozitia[i-1][j];
            else
                sumaMaximaPePozitia[i][j] += max(sumaMaximaPePozitia[i-1][j-1], sumaMaximaPePozitia[i-1][j]);
        }
    }

    // pentru a afisa traseul gasim maximul de pe ultima linie si mergem in sus si in stanga-sus pe maxim ditnre ele

    for (int k = 0; k < triunghi.size(); ++k) {
        for (int i = 0; i < k + 1; ++i) {
            //cout<<triunghi[k][i]<<' ';
            cout<<sumaMaximaPePozitia[k][i]<<' ';
        }
        cout<<'\n';
    }

}

int main() {
    fstream f ("E:\\FACULTATE\\SEM1\\TAP\\listaProbleme\\PD\\triunghiData.txt");
    vector<vector<int>> v(4);
    for (int i = 0; i < 4; ++i) {
        v[i].resize(4);
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            f >> v[i][j];
        }
    }

    calculTraseuMaxim(v);
}