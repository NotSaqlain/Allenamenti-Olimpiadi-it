// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> H, V;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    // insert your code here
    int sumH = 0;
    int sumV = 0;
    int minH = H[0];
    int minV = V[0];
    for (int i = 0; i < N; i++) {
        sumH += H[i];
        sumV += V[i];
        if (H[i] < minH) minH = H[i];
        if (V[i] < minV) minV = V[i];
        
    }
    
    if (sumH > sumV) {
        cout << "Verstappen" << endl;
    } else {
        cout << "Hamilton" << endl;
    }
    
    if (minH < minV){
        cout << "Hamilton" << endl;
    } else {
        cout << "Verstappen";
    }
    
    

    return 0;
}
