#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
Per rendere ancora più sicure le comunicazioni segrete tra gli smartphone durante l’esame di maturità,
gli studenti stanno ponderando l’eventualità di cifrare tutti i messaggi che si scambieranno. Nel corso
dell’ultimo anno scolastico hanno infatti studiato l’algoritmo di cifratura asimmetrica RSA. L’idea è
semplice: realizzare un’app che cifri i messaggi e un’altra che li decifri; in questo modo anche qualora i
commissari dovessero intercettarli non riuscirebbero a leggerne il contenuto!
La maturità si avvicina e i lavori per l’app di decifratura sono ancora in alto mare. In estrema sintesi1
,
ti viene fornita una coppia di interi N e d che costituiscono la “chiave privata”. Ogni intero c, che
rappresenta un carattere cifrato, si decifra calcolando c^d mod N


• Subtask 1 [ 0 punti]: Casi d’esempio.
• Subtask 2 [25 punti]: L = 1, messaggio[0] ≤ 1 000, d = 3.
• Subtask 3 [25 punti]: N ≤ 1 000 000, L = 1.
• Subtask 4 [10 punti]: N ≤ 1 000 000.
• Subtask 5 [40 punti]: Nessuna limitazione specifica.

esempio:
stdin
145 3 1
119

stdout
r

*/

static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int* messaggio;
static char* plaintext;

// Declaring functions
void decifra(int N, int d, int L, int* messaggio, char* plaintext){
	for (int i = 0; i < L; i++){
		plaintext[i] = (char) (messaggio[i] * messaggio[i] * messaggio[i] % N);
	}
	plaintext[L] = '\0';
}

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
        fscanf(fr, "%d %d %d", &N, &d, &L);
	messaggio = (int*)malloc(100 * sizeof(int));
	plaintext = (char*)malloc(110 * sizeof(char));
	for (i0 = 0; i0 < L; i0++)
            fscanf(fr, "%d", &messaggio[i0]);

	// Calling functions
	decifra(N, d, L, messaggio, plaintext);

	// Writing output
        fprintf(fw, "%s\n", plaintext);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
