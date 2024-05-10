#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 
#include <numeric>

using namespace std;

int Solve(int N, std::vector<int>& V) {
    int risposta;

    risposta = V[0];
    for (int i = 1; i < N; ++i) {
        risposta = std::lcm(risposta, V[i]);
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