#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void llenarmatriz(int filas, int columnas, int matriz[filas][columnas]) {
    int i, j;
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 10;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multpmatrices(int filas, int columnas, int A[filas][columnas], int B[filas][columnas], int C[filas][columnas]) {
    int i, j, k, temporal;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            temporal = 0;
            for (k = 0; k < columnas; k++) {
                temporal += A[i][k] * B[k][j];
            }
            C[i][j] = temporal;
        }
    }
}

int main() {
	
    srand(time(NULL));
    int filas = 30;
    int columnas = 30;
    int A[filas][columnas];
    int B[filas][columnas];
    int C[filas][columnas];
    int i, j;

    printf("Matriz A:\n");
    llenarmatriz(filas, columnas, A);

    printf("\nMatriz B:\n");
    llenarmatriz(filas, columnas, B);
    
    clock_t tic = clock();
    
    multpmatrices(filas, columnas, A, B, C);
    
    clock_t toc = clock();
	double tiempotranscurrido = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;

    printf("\nMatriz C:\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\nElapsed time: %.2f milliseconds\n", tiempotranscurrido);
    
    return 0;
}


