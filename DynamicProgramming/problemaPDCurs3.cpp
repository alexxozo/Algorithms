//Se da un ¸sir de caractere s. S˘a se determine cel mai lung sub¸sir al lui
//        s far˘a repetit¸ii.
//Pentru ¸sirul a = ”xaxyxayy” LMAX=3. (”yxa”) Pentru ¸sirul a =
//”xaxyxazy” LMAX=4. (”yxaz”)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void subsecventaFaraRepetitii(string s) {
    vector<int> celMaiLungaSubsecventaUnicaPanaLa(s.size(), 1);
    for (int i = 1; i < s.size(); ++i) {
        int detectatRepetitieLa = -1;
        for (int j = 0; j < i; ++j) {
            if (s[i] == s[j]) {
                detectatRepetitieLa = j;
            }
        }
        if (detectatRepetitieLa != -1 && detectatRepetitieLa >= i - celMaiLungaSubsecventaUnicaPanaLa[i - 1]) {
            celMaiLungaSubsecventaUnicaPanaLa[i] = i - detectatRepetitieLa;
        } else {
            celMaiLungaSubsecventaUnicaPanaLa[i] = celMaiLungaSubsecventaUnicaPanaLa[i - 1] + 1;
        }
    }

    for (int k = 0; k < s.size(); ++k) {
        cout<<celMaiLungaSubsecventaUnicaPanaLa[k]<<' ';
    }

    int maxim = INT_MIN;
    for (int l = 0; l < s.size(); ++l) {
        if (maxim < celMaiLungaSubsecventaUnicaPanaLa[l]) {
            maxim = celMaiLungaSubsecventaUnicaPanaLa[l];
        }
    }
    cout<<'\n'<<maxim;
}

int main() {
    subsecventaFaraRepetitii("xaxyxayy");
}

