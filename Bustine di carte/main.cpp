#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int scarta(int C, vector<bool> L, vector<bool> D, vector<bool> N) {
    int numLaura = 0;
    int numDaria = 0;
    int numNoemi = 0;
    
    for (int i = 0; i < C; i++) {
        numLaura += (L[i] && !D[i] && !N[i]);
        numDaria += (!L[i] && D[i] && !N[i]);
        numNoemi += (!L[i] && !D[i] && N[i]);
    }
    return C - (numLaura + numDaria + numNoemi);
}

int main() {

  ifstream cin("input.txt");
  ofstream cout("output.txt");

  int C;
  cin >> C;

  vector<bool> L(C, false), D(C, false), N(C, false);
  for (int i = 0; i < C; i++) {
    int l, d, n;
    cin >> l >> d >> n;
    if (l) L[i] = true;
    if (d) D[i] = true;
    if (n) N[i] = true;
  }

  cout << scarta(C, L, D, N);

  return 0;
}
