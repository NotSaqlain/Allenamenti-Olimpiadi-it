#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <map>

using namespace std;

map<long long, bool> autogrill_stato;

void inizia() {
    autogrill_stato.clear();
}

void apri(long long p) {
    autogrill_stato[p] = true;
}

void chiudi(long long p) {
    autogrill_stato[p] = false;
}

long long chiedi(long long p) {
    for (auto it = autogrill_stato.begin(); it != autogrill_stato.end(); ++it) {
        if (it->second) {
            return it->first;
        }
    }
    return -1;
}

int main() {
    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}