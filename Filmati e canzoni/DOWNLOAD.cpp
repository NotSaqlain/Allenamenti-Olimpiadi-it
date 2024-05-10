#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;
    

    for (t = 1; t <= T; t++) {
        int N, F, C;
        
        // scrivi in queste variabili la risposta
        int nf = 0;
        int nc = 0;

        cin >> N >> F >> C;

        // RISOLVI QUI IL PROBLEMA!!
        nf = min(N / F, N);
        int remaining = N - nf * F;
        nc = remaining / C;

        cout << "Case #" << t << ": " << nf << " " << nc << endl;
    }
}
