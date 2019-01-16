#include<iostream>
#include <vector>

using namespace std;

/*
 * 'abxcayb' si 'aybcx' => 'abc' L = 3
 * subsir inseamna ca nu trb sa fie consecutive
 *  asemanatoare cu distantade editare
 *  m[i][j] = 1 + m[i-1][j-1] daca a[i] == b[j] // pentru ca in mom de fata avem incluse ultimele litere din subsiruri iar daca acestea sunt egale e clar ca va trebui sa incrementam cu 1 m[i-1][j-1] reprezinta cuvintele fara cele 2 litere adaugate
 *          = max(m[i-1][j], m[i][j-1]) // pentru ca trbuie sa alegem varianta maximala intre cuvantul1 - ultima litera si cuvantul2 - ultima litera
 *
 */

void subsirComunMaximal(string cuvant1, string cuvant2) {
    vector<vector<int>> numarMaximDeLitereIdenticeIntre(cuvant2.size() + 1);
    for (int i = 0; i < cuvant2.size() + 1; ++i) {
        numarMaximDeLitereIdenticeIntre[i].resize(cuvant1.size() + 1);
    }

    // nu e neaprat nevoie
    for (int j = 1; j < cuvant1.size() + 1; ++j) {
        numarMaximDeLitereIdenticeIntre[0][j] = 0;
    }
    for (int j = 1; j < cuvant2.size() + 1; ++j) {
        numarMaximDeLitereIdenticeIntre[j][0] = 0;
    }

    for (int i = 1; i < numarMaximDeLitereIdenticeIntre.size(); ++i) {
        for (int j = 1; j < numarMaximDeLitereIdenticeIntre[i].size(); ++j) {
            if (cuvant2[i - 1] == cuvant1[j - 1]) {
                numarMaximDeLitereIdenticeIntre[i][j] = 1 + numarMaximDeLitereIdenticeIntre[i - 1][j - 1];
            } else {
                numarMaximDeLitereIdenticeIntre[i][j] = max(numarMaximDeLitereIdenticeIntre[i][j - 1], numarMaximDeLitereIdenticeIntre[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < numarMaximDeLitereIdenticeIntre.size(); i++) {
        for (int j = 0; j < numarMaximDeLitereIdenticeIntre[i].size(); j++) {
            cout << numarMaximDeLitereIdenticeIntre[i][j] << ' ';
        }
        cout<<endl;
    }

    // creeare subsir
    int iInit = numarMaximDeLitereIdenticeIntre.size() - 1, jInit = numarMaximDeLitereIdenticeIntre[0].size() - 1;
    while (iInit != 0 && jInit != 0) {
        if (cuvant1[jInit - 1] == cuvant2[iInit - 1] && numarMaximDeLitereIdenticeIntre[iInit][jInit] == numarMaximDeLitereIdenticeIntre[iInit - 1][jInit - 1] + 1) {
            cout<<cuvant2[iInit - 1]<<' ';
            iInit--;
            jInit--;
        } else if (numarMaximDeLitereIdenticeIntre[iInit][jInit] == numarMaximDeLitereIdenticeIntre[iInit][jInit - 1]) {
            jInit--;
        } else if (numarMaximDeLitereIdenticeIntre[iInit][jInit] == numarMaximDeLitereIdenticeIntre[iInit - 1][jInit]) {
            iInit--;
        }
    }
}

// acelasi lucru numai ca trebuie sa fie consecutive
void subsecventaComunaMaximala(string cuvant1, string cuvant2) {
    vector<vector<int>> numarMaximDeLitereIdenticeConsecutiveIntre(cuvant2.size() + 1);
    for (int i = 0; i < cuvant2.size() + 1; ++i) {
        numarMaximDeLitereIdenticeConsecutiveIntre[i].resize(cuvant1.size() + 1);
    }

    // nu e neaprat nevoie
    for (int j = 1; j < cuvant1.size() + 1; ++j) {
        numarMaximDeLitereIdenticeConsecutiveIntre[0][j] = 0;
    }
    for (int j = 1; j < cuvant2.size() + 1; ++j) {
        numarMaximDeLitereIdenticeConsecutiveIntre[j][0] = 0;
    }

    for (int i = 1; i < numarMaximDeLitereIdenticeConsecutiveIntre.size(); ++i) {
        for (int j = 1; j < numarMaximDeLitereIdenticeConsecutiveIntre[i].size(); ++j) {
            if (cuvant2[i - 1] == cuvant1[j - 1]) {
                numarMaximDeLitereIdenticeConsecutiveIntre[i][j] = 1 + numarMaximDeLitereIdenticeConsecutiveIntre[i - 1][j - 1];
            } else {
                numarMaximDeLitereIdenticeConsecutiveIntre[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < numarMaximDeLitereIdenticeConsecutiveIntre.size(); i++) {
        for (int j = 0; j < numarMaximDeLitereIdenticeConsecutiveIntre[i].size(); j++) {
            cout << numarMaximDeLitereIdenticeConsecutiveIntre[i][j] << ' ';
        }
        cout<<endl;
    }

    int maxim = 0, iInit, jInit;
    for (int i = 0; i < numarMaximDeLitereIdenticeConsecutiveIntre.size(); i++) {
        for (int j = 0; j < numarMaximDeLitereIdenticeConsecutiveIntre[i].size(); j++) {
            if (numarMaximDeLitereIdenticeConsecutiveIntre[i][j] > maxim) {
                maxim = numarMaximDeLitereIdenticeConsecutiveIntre[i][j];
                iInit = i;
                jInit = j;
            }
        }
    }


    // creeare subsir
    while (iInit != 0 && jInit != 0) {
        cout<<cuvant2[iInit - 1]<<' ';
        iInit--;
        jInit--;
    }
}

int main() {
    //subsirComunMaximal("abcdaf", "acbcf");
    subsecventaComunaMaximala("xyzxcd", "cdxyzx");
}