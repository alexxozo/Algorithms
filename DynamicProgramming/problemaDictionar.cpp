#include<iostream>
#include <vector>

using namespace std;

/*
 * Problema Dictionar
 *  s = " xyzzzzxy"
    dict = {"xyz", "zzz", "zzzz", "x", "y", "xy"}
    nr minim de subsiruri care apartin de dict si apar in s
 */

bool existaInVector(string cautat, vector<string> v) {
    for (int i = 0; i < v.size(); ++i) {
        if (cautat == v[i]) return true;
    }
    return false;
}

void numarMinimDeSubsiruri(vector<string> dictionar, string s) {
    vector<int> nrMinimDeSubsiruriPanaLa(s.size(), -1);
    nrMinimDeSubsiruriPanaLa[0] = 0;
    vector<int> pred(s.size(), -1);

    for (int i = 1; i < s.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (existaInVector(s.substr(j, i - j + 1), dictionar)) {
                if ((nrMinimDeSubsiruriPanaLa[j - 1] + 1 < nrMinimDeSubsiruriPanaLa[i] || nrMinimDeSubsiruriPanaLa[i] == -1 ) && nrMinimDeSubsiruriPanaLa[j - 1] != -1) {
                    nrMinimDeSubsiruriPanaLa[i] = nrMinimDeSubsiruriPanaLa[j - 1] + 1;
                    pred[i] = j - 1;
                }
            }
        }
    }

    cout << "Sirul se poate imparti in: " << nrMinimDeSubsiruriPanaLa[nrMinimDeSubsiruriPanaLa.size() - 1];

    int i = nrMinimDeSubsiruriPanaLa.size() - 1;
    while (pred[i] > 1) {
        cout << '\n' << s.substr(pred[i] + 1, i - pred[i]);
        i = pred[i];
    }
    cout << '\n' << s.substr(pred[i] + 1, i - pred[i]);

}

int main() {
    vector<string> dictionar = {"xyz", "zzz", "zzzz", "x", "y", "xy"};
    numarMinimDeSubsiruri(dictionar, " xyzzzzxy");
}
