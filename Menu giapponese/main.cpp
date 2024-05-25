#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    
    int N, M;
    cin >> N >> M;

    vector<int> array(N);
    for(int i = 0; i < N; ++i) {
        cin >> array[i];
    }
    
    int val1, val2;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (sum < array[i] + array[j] && array[i] + array[j] <= M) {
                sum = array[i] + array[j];
                val1 = i;
                val2 = j;
            }
        }
    }
    
    cout << array[val1] << "\n" << array[val2];
    
    return 0;
}
