#include <iostream>
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

bool autogrill_stato[1018] = {false};

void inizia() {
    for (int i = 0; i < 1018; ++i) {
        autogrill_stato[i] = false;
    }
}

void apri(long long p) {
    autogrill_stato[p - 1] = true;
}

void chiudi(long long p) {
    autogrill_stato[p - 1] = false;
}

long long chiedi(long long p) {
    for (int i = p - 1; i < 1018; ++i) {
        if (autogrill_stato[i]) {
            return i + 1;
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
