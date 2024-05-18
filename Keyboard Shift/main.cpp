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
        int index = keyboard.find(S[i]);
        S[i] = keyboard[index + 1];
    }

    // output data

    cout << S << endl;
    return 0;
}
