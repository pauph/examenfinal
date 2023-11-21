#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaBinaria(int lista[], int num, int elemento) {
    int primero = 0, ultimo = num - 1, mitad;

    while (primero <= ultimo) {
        mitad = (primero + ultimo) / 2;
        if (lista[mitad] < elemento) {
            primero = mitad + 1;
        } else if (lista[mitad] == elemento) {
            return mitad;
        } else {
            ultimo = mitad - 1;
        }
    }

    return -1;
}

void ordenarArreglo(int lista[], int num) {
    int i, j, temp;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int busquedaSecuencial(int lista[], int num, int elemento) {
    int i;
    for (i = 0; i < num; i++) {
        if (lista[i] == elemento) {
            return i + 1; 
        }
    }
    return -1; 
}

int main() {
    int i, j, num = 50000, elemento, posicion;

    srand(time(NULL));
    int lista[num];

    for (i = 0; i < num; i++) {
        lista[i] = rand() % 50000;
    }
    
    ordenarArreglo(lista, num);

    double tiempoMinSecuencial = 10000, tiempoMaxSecuencial = 0, tiempoPromedioSecuencial = 0;
    double tiempoMinBinaria = 10000, tiempoMaxBinaria = 0, tiempoPromedioBinaria = 0;

    printf("Busqueda Secuencial:\n");
    for (j = 0; j < 100; j++) {
        elemento = lista[rand() % num];

        clock_t tic = clock(); 
        posicion = busquedaSecuencial(lista, num, elemento);
        clock_t toc = clock();
        double tiempotranscurrido = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;

        tiempoMinSecuencial = (tiempotranscurrido < tiempoMinSecuencial) ? tiempotranscurrido : tiempoMinSecuencial;
        tiempoMaxSecuencial = (tiempotranscurrido > tiempoMaxSecuencial) ? tiempotranscurrido : tiempoMaxSecuencial;
        tiempoPromedioSecuencial += tiempotranscurrido;

        printf("Tiempo %d: %.2f ms\n", j + 1, tiempotranscurrido);
    }

    tiempoPromedioSecuencial /= 100;
    printf("\nTiempo Min: %.2f ms\n", tiempoMinSecuencial);
    printf("Tiempo Max: %.2f ms\n", tiempoMaxSecuencial);
    printf("Tiempo Promedio: %.2f ms\n", tiempoPromedioSecuencial);

    printf("\nBusqueda Binaria:\n");
    for (j = 0; j < 100; j++) {
        elemento = lista[rand() % num];

        clock_t tic = clock(); 
        posicion = busquedaBinaria(lista, num, elemento);
        clock_t toc = clock();
        double tiempotranscurrido = ((double)(toc - tic) / CLOCKS_PER_SEC) * 1000.0;

        tiempoMinBinaria = (tiempotranscurrido < tiempoMinBinaria) ? tiempotranscurrido : tiempoMinBinaria;
        tiempoMaxBinaria = (tiempotranscurrido > tiempoMaxBinaria) ? tiempotranscurrido : tiempoMaxBinaria;
        tiempoPromedioBinaria += tiempotranscurrido;

        printf("Tiempo %d: %.2f ms\n", j + 1, tiempotranscurrido);
    }

    tiempoPromedioBinaria /= 100;
    printf("\nTiempo Min: %.2f ms\n", tiempoMinBinaria);
    printf("Tiempo Max: %.2f ms\n", tiempoMaxBinaria);
    printf("Tiempo Promedio: %.2f ms\n", tiempoPromedioBinaria);

    return 0;
}


