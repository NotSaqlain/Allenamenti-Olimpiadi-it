#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 

using namespace std;

int mcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mcm(int a, int b) {
    return std::abs(a * b) / mcd(a, b);
}

int Solve(int N, vector<int>& V) {
    int risposta;

    // Add your code here...
    risposta = V[0];
    for (int i = 1; i < N; ++i) {
        risposta = mcm(risposta, V[i]);
    }
    return risposta;
}

int main() {
    ifstream inputStream("input.txt");
    ofstream outputStream("output.txt");

    int T;
    inputStream >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        inputStream >> N;

        vector<int> V(N);

        for (int i = 0; i < N; i++) {
            inputStream >> V[i];
        }

        int risposta = Solve(N, V);

        outputStream << "Case #" << t << ": " << risposta << endl;
        outputStream.flush();
    }

    inputStream.close();
    outputStream.close();

    return 0;
}
