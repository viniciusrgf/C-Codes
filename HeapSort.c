#include <stdio.h>
#include <time.h>

void heapsort(int *vet, int n) {
	int i, tmp;


	for (i = (n / 2); i >= 0; i--) {
		heap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		heap(vet, 0, i-1);
	}
}

void heap(int *vet, int raiz, int fundo) {
	int pronto, fi, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			fi = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			fi = raiz * 2;
		}
		else {
			fi = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[fi]) {
		tmp = vet[raiz];
		vet[raiz] = vet[fi];
		vet[fi] = tmp;
		raiz = fi;
    }
	else {
      pronto = 1;
	}
  }
}

int main() {
    int n, i, j;
    	clock_t Ticks[2];
Ticks[0] = clock ();
	printf ("qnts numeros/"); //pede os numeros do array
    scanf ("%d", &n);
int vetor[n];
for (i = 0; i < n; i++){
    vetor[i] = rand () % n;//preenche com numeros aleatorios
    }
	heapsort(vetor,n);
	for (i = 0; i < n; i++) {
		printf("%d ", vetor[i]);
	}
	Ticks[1] = clock ();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf ("\nTempo gasto: %g ms.", Tempo);
	return(0);
}