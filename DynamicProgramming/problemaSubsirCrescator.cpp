#include<iostream>
#include <vector>
#include <climits>

using namespace std;

void subsirCrescator(vector<int> v) {
    vector<int> celMaiLungSubsirPanaLa(v.size(), 1);
    vector<int> pred(v.size(), -1);
    for (int i = 0; i < v.size(); ++i) {
        int maxim = 0;
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i] && maxim < celMaiLungSubsirPanaLa[j]) {
                maxim = celMaiLungSubsirPanaLa[j];
                pred[i] = j;
            }
        }
        celMaiLungSubsirPanaLa[i] = 1 + maxim;
    }
    for (int k = 0; k < v.size(); ++k) {
        cout<<celMaiLungSubsirPanaLa[k]<<' ';
    }
    cout<<endl;
    for (int k = 0; k < v.size(); ++k) {
        cout << pred[k] << ' ';
    }
    cout<<"\nUnul dintre subsirurile de lungime maxima este: ";
    int pozStart = -1;
    int maxim = INT_MIN;
    for (int l = 0; l < v.size(); ++l) {
        if (maxim < celMaiLungSubsirPanaLa[l]) {
            maxim = celMaiLungSubsirPanaLa[l];
            pozStart = l;
        }
    }
    while (pred[pozStart] != -1) {
        cout<<v[pozStart]<<' ';
        pozStart = pred[pozStart];
    }
    cout<<v[pozStart];
}

int main() {
    subsirCrescator({ 6, 3, 5, 10, 12, 2, 9, 15, 14, 7, 4, 8,13});
}