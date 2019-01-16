#include <iostream>
using namespace std;
//# n = n - 1
//# n = n / 2 pt n % 2 == 0
//# n = n / 3 pt n % 3 == 0
//# nr minim de operatii pana cand n e 1?
//
//# varianta recursiva care alege intre optiuni

int M(int n) {
    if (n == 1) {
        return 0;
    } else {
        int n1, n2, n3;
        n2 = n3 = n;
        n1 = M(n - 1);
        if (n % 2 == 0) {
            n2 = M(n / 2);
        } else if (n % 3 == 0) {
            n3 = M(n / 3);
        }
        return 1 + min(min(n1, n2), n3);
    }
}

// memoization recursiv
int N(int n, int valoriAnterioare[]) {
    if (n == 1) {
        return 0;
    } else {
        int n1, n2, n3;
        n2 = n3 = n;

        if (valoriAnterioare[n - 1] == -1)
            valoriAnterioare[n - 1] = n1 = N(n - 1, valoriAnterioare);
        n1 = valoriAnterioare[n - 1];

        if (n % 2 == 0) {
            if (valoriAnterioare[n / 2] == -1)
                valoriAnterioare[n / 2] = n2 = N(n / 2, valoriAnterioare);
            n2 = valoriAnterioare[n / 2];
        } else if (n % 3 == 0) {
            if (valoriAnterioare[n / 3] == -1)
                valoriAnterioare[n / 3] = n3 = N(n / 3, valoriAnterioare);
            n3 = valoriAnterioare[n / 3];
        }
        return 1 + min(min(n1, n2), n3);
    }
}

// Programare dinamica
void PD(int n) {
    int valori[n + 1];
    for (int i = 1; i < n + 1; ++i) {
        valori[i] = 0;
    }

    valori[1] = 0;
    for (int i = 2; i < n + 1; ++i) {
        int n1, n2, n3;
        n2 = n3 = i;
        n1 = valori[i - 1];
        if (i % 2 == 0) n2 = valori[i / 2];
        else if (i % 3 ==0) n3 = valori[i / 3];
        valori[i] = 1 + min(min(n1, n2), n3);
    }
    cout << valori[n];
}

int main() {
    //int valori[10];
    ///for (int i = 0; i < 10; ++i) {
    //    valori[i] = -1;
    //}
    //cout << N(10, valori);
    PD(5);
    return 0;
}