// Se da un vector v de numere naturale. Se porneste de la pozitia i = 1
//a lui v. Se cere num˘arul minim de pa¸si ˆın care se poate ajunge pe
//pozit¸ia n dac˘a v[i] = k are semnificat¸ia: de la pozit¸ia i se poate ajunge
//(vizita) la oricare dintre pozitiile i + 1,i + 2,i + k, ˆıntr-un singur pas.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimPasi(vector<int> v) {
    vector<int> nrMinimPasiPanaLaPozitia(v.size(), 0);
    nrMinimPasiPanaLaPozitia[0] = 0;
    for (int i = 1; i < v.size(); ++i) {
        int minim = INT_MAX;
        for (int j = 0; j < i; ++j) {
            if (v[j] + j >= i && minim > nrMinimPasiPanaLaPozitia[j])
                minim = nrMinimPasiPanaLaPozitia[j];
        }
        nrMinimPasiPanaLaPozitia[i] = 1 + minim;
    }
    for (int k = 0; k < v.size(); ++k) {
        cout<<nrMinimPasiPanaLaPozitia[k]<<' ';
    }
    return nrMinimPasiPanaLaPozitia[v.size() - 1];
}

int main() {
    vector<int> v = {3,2,1,0,4};
    minimPasi(v);
}
