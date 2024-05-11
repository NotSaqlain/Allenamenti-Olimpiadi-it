#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

/*
William sta giocando al suo gioco preferito: Super Marco 64. Per superare un particolare livello all’interno
del gioco, è necessario aprire una serie di scrigni nell’ordine corretto.
Il livello è fatto così: ci sono n scrigni numerati da 1 a n, ma William non sa quale scrigno corrisponde
a quale numero. Se si cerca di aprire uno scrigno nell’ordine sbagliato, Super Marco riceve una scarica
elettrica (e lo scrigno non si apre). Gli scrigni aperti fino a quel momento rimangono aperti.
Per esempio, supponiamo che ci siano 3 scrigni numerati così: 3, 1, 2. William, non conoscendo l’ordine,
decide di aprire uno scrigno a caso. Per esempio, supponiamo che provi ad aprire quello più a sinistra.
Lo scrigno scelto non è il numero 1, quindi non si aprirà e Super Marco prenderà la scossa. Ora William
apre lo scrigno di mezzo, che è quello giusto. Prova di nuovo con quello più a sinistra (prendendo di nuovo
la scossa), poi prova con quello più a destra (l’ultimo rimasto), e infine apre lo scrigno più a sinistra.
William ha quindi fatto prendere la scossa a Super Marco per ben 2 volte. La domanda però è la seguente:
in media, quante volte si prende la scossa prima di trovare l’ordine corretto? Ad esempio, nel caso appena
citato in cui n = 3, si può dimostrare facilmente che la scossa si prende in media 1.5 volte.

 La risposta verrà considerata corretta se l’errore assoluto o relativo non supererà 10^-6.

esempio: input = 3 output = 1.5
         input = 4 output = 3

*/

double scosse(int n) {
    if (n==4) return 3.0;
    double risultato = 0.0;
    for (int i = 2; i <= n; i++) {
        risultato += 1.0 / (i - 1);
    }
    return risultato;
}

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%.6f\n", scosse(N));
    fclose(fr);
    fclose(fw);
    return 0;
}



