#include<iostream>
#include <vector>
#include <climits>

using namespace std;

// primul subpunct cere cate palindroame sunt
/*
 *  vom folosi o matrice de tipul
 *  s = "anabana"
 *  liniile semnifica lungimea cuvantului format
 *  si coloana semnifica ultima litera a acestuia
 *  diag principala si cea de dupa vor fi completate inainte
 *  iar apoi pentru celelalte valori de deasupra diag vom copia val din stanga jos daca
 *  s[i] == s[j] deoarece asa stim faptul ca cuvantul fara i si j deja este palindrom iar
 *  daca i si j sunt egale atunci si cuvantul cu i si j adaugate va fi palindrom
 *    a n a b a n a
 *  a 1 0
 *  n   1 0
 *  a     1 0
 *  b       1 0
 *  a         1 0
 *  n           1 0
 *  a             1 0
 */
void catePalindroameSuntInTotalSiPartitionare(string s) {
    vector<vector<int>> matricePalindroame(s.size());
    for (int i = 0; i < s.size(); ++i) {
        matricePalindroame[i].resize(s.size(), 0);
    }

    for (int j = 0; j < s.size(); ++j) {
        matricePalindroame[j][j] = 1;
    }

    for (int i = 1; i < s.size() ; ++i) {
        if (s[i - 1] == s[i]) {
            matricePalindroame[i][i + 1] = 1;
        }
    }

    for (int lungime = 3; lungime <= s.size(); ++lungime) {
        for (int i = 0; i < s.size() - lungime + 1; ++i) {
            int j = i + lungime - 1;
            if (s[i] == s[j] && matricePalindroame[i + 1][j - 1]) {
                matricePalindroame[i][j] = 1;
            }
        }
    }

    int nrPalindroame = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            cout << matricePalindroame[i][j] << ' ';
            if (matricePalindroame[i][j]) nrPalindroame++;
        }
        cout<<endl;
    }

    cout<<nrPalindroame<<endl;

    // partitionare
    vector<int> numarMinimDePalindroameInCareImpartPanaLa(s.size(), INT_MIN);
    numarMinimDePalindroameInCareImpartPanaLa[0] = 1;
    for (int i = 1; i < numarMinimDePalindroameInCareImpartPanaLa.size(); ++i) {
        int minim = numarMinimDePalindroameInCareImpartPanaLa[i - 1];
        for (int j = 1; j < i + 1; ++j) {
            if (matricePalindroame[j][i - j]) {
                minim = numarMinimDePalindroameInCareImpartPanaLa[j - 1] + 1;
            }
        }
        numarMinimDePalindroameInCareImpartPanaLa[i] = minim;
    }

    for (int i = 0; i < numarMinimDePalindroameInCareImpartPanaLa.size(); ++i) {
        cout<<numarMinimDePalindroameInCareImpartPanaLa[i]<<' ';
    }

    cout<<"\nNr minim de partitionari: "<<numarMinimDePalindroameInCareImpartPanaLa[s.size() - 1] - 1;
}

int main() {
    catePalindroameSuntInTotalSiPartitionare("aaacaaba");
}
