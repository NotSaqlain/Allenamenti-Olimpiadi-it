#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input data
int N;
string S;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin >> S;

    // insert your code here
    string keyboard = "qwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < S.size(); i++) {
        int tasto = keyboard.find(S[i]);
        S[i] = keyboard[tasto + 1];
    }

    cout << S << endl;
    return 0;
}
