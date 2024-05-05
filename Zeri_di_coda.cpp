#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAXN 100000

int zeri(int N, char S[]) {
    std::string str(S, N);
    
    int num = 1;
    size_t pos = 0;
    
    while (str.find('x') != std::string::npos) {
        pos = str.find('x');
        num *= std::stoi(str.substr(0, pos));
        str = str.substr(pos + 1);
    }
    num *= std::stoi(str);
    
    int numStr = std::to_string(num).length();
    int array[numStr];
    
    int temp = num;
    for (int k = numStr - 1; k >= 0; k--) {
        array[k] = temp % 10;
        temp /= 10;
    }
    
    int zeri = 0;
    for (int y = numStr - 1; y >= 0 && array[y] == 0; y--){
        zeri++;
    }
    
    return zeri;
}


char S[MAXN + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", zeri(strlen(S), S));
    fclose(fr);
    fclose(fw);
    return 0;
}
