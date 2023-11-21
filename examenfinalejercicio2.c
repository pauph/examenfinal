#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirLista(int lista[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d ", lista[i]);
    }
    printf("\n");
}

void bubblesort(int lista[], int n);
void bubblesort(int lista[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void quicksort(int lista[], int primero, int ultimo);
void quicksort(int lista[], int primero, int ultimo) {
    int pivot, i, j, temp;
    if (primero < ultimo) {
        pivot = primero;
        i = primero;
        j = ultimo;
        while (i < j) {
            while (lista[i] <= lista[pivot] && i <= ultimo) {
                i++;
            }
            while (lista[j] > lista[pivot] && j >= primero) {
                j--;
            }
            if (i < j) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
        temp = lista[j];
        lista[j] = lista[pivot];
        lista[pivot] = temp;
        quicksort(lista, primero, j - 1);
        quicksort(lista, j + 1, ultimo);
    }
}

void inserctionsort(int lista[], int n);
void inserctionsort(int lista[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        int numeroActual = lista[i];
        int posAnterior = i - 1;

        while (posAnterior >= 0 && lista[posAnterior] > numeroActual) {
            lista[posAnterior + 1] = lista[posAnterior];
            posAnterior--;
        }

        lista[posAnterior + 1] = numeroActual;
    }
}

int main() {

    int n = 10000, i, j;
    srand(time(NULL));
    int listaBubblesort[n];
    int listaQuicksort[n];
    int listaInsertionsort[n];

    double tiempoBubblesort[100];
    double tiempoQuicksort[100];
    double tiempoInsertionsort[100];

    double tiempoMinBubblesort = 10000, tiempoMaxBubblesort = 0, tiempoPromedioBubblesort = 0;
    double tiempoMinQuicksort = 10000, tiempoMaxQuicksort = 0, tiempoPromedioQuicksort = 0;
    double tiempoMinInsertionsort = 10000, tiempoMaxInsertionsort = 0, tiempoPromedioInsertionsort = 0;

    for (j = 0; j < 100; j++) {

        for (i = 0; i < n; i++) {
            listaBubblesort[i] = rand() % 10000;
            listaQuicksort[i] = listaBubblesort[i];
            listaInsertionsort[i] = listaBubblesort[i];
        }

        clock_t tic = clock();
        bubblesort(listaBubblesort, n);
        clock_t toc = clock();
        tiempoBubblesort[j] = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;
        tiempoMinBubblesort = (tiempoBubblesort[j] < tiempoMinBubblesort) ? tiempoBubblesort[j] : tiempoMinBubblesort;
        tiempoMaxBubblesort = (tiempoBubblesort[j] > tiempoMaxBubblesort) ? tiempoBubblesort[j] : tiempoMaxBubblesort;
        tiempoPromedioBubblesort += tiempoBubblesort[j];

        tic = clock();
        quicksort(listaQuicksort, 0, n - 1);
        toc = clock();
        tiempoQuicksort[j] = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;
        tiempoMinQuicksort = fmin(tiempoQuicksort[j], tiempoMinQuicksort);
        tiempoMaxQuicksort = fmax(tiempoQuicksort[j], tiempoMaxQuicksort);
        tiempoPromedioQuicksort += tiempoQuicksort[j];

        tic = clock();
        inserctionsort(listaInsertionsort, n);
        toc = clock();
        tiempoInsertionsort[j] = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;
        tiempoMinInsertionsort = fmin(tiempoInsertionsort[j], tiempoMinInsertionsort);
        tiempoMaxInsertionsort = fmax(tiempoInsertionsort[j], tiempoMaxInsertionsort);
        tiempoPromedioInsertionsort += tiempoInsertionsort[j];
    }

    tiempoPromedioBubblesort /= 100;
    tiempoPromedioQuicksort /= 100;
    tiempoPromedioInsertionsort /= 100;

    printf("Bubblesort:\n");
    for (j = 0; j < 100; j++) {
        printf("Tiempo %d: %.2f \n", j + 1, tiempoBubblesort[j]);
    }
    printf("\nTiempo Min: %.2f ms\n", tiempoMinBubblesort);
    printf("Tiempo Max: %.2f ms\n", tiempoMaxBubblesort);
    printf("Tiempo Promedio: %.2f ms\n\n", tiempoPromedioBubblesort);

    printf("Quicksort:\n");
    for (j = 0; j < 100; j++) {
        printf("Tiempo %d: %.2f \n", j + 1, tiempoQuicksort[j]);
    }
    printf("\nTiempo Min: %.2f ms\n", tiempoMinQuicksort);
    printf("Tiempo Max: %.2f ms\n", tiempoMaxQuicksort);
    printf("Tiempo Promedio: %.2f ms\n\n", tiempoPromedioQuicksort);

    printf("Insertionsort:\n");
    for (j = 0; j < 100; j++) {
        printf("Tiempo %d: %.2f \n", j + 1, tiempoInsertionsort[j]);
    }
    printf("\nTiempo Min: %.2f ms\n", tiempoMinInsertionsort);
    printf("Tiempo Max: %.2f ms\n", tiempoMaxInsertionsort);
    printf("Tiempo Promedio: %.2f ms\n", tiempoPromedioInsertionsort);

    return 0;
}

