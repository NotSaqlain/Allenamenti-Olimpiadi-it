#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    if (N < 0) return 0;
    if (M < 0) return N * A;
    if (A < 0 || B < 0) {
        if (A < B) {
            return A;
        } else {
            return B;
        }
    }
    if (( A*N) < B ) {
        return A*N;
    } else if(N > M) {
        int temp = N/M;
        int a = N - M*temp;
        if (a * A < B) return (temp * B) + A*a;
        return (temp * B) + B;
    } else if (N == M) {
        if (A < B) {
            return A;
        } else {
            return B;
        }
    } else if (M > N) {
        if (( A*N) < B ) {
            return A*N;
        }
    }
    return B;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
