#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matriz_por_vetor_por_linha(float **matriz, float *vetor, float *resultado, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
}



void matriz_por_vetor_por_coluna(float **matriz, float *vetor, float *resultado, int n) {
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
   
}

int main(int argc, char **argv) {
    int n =  atoi(argv[1]);
    int inverter = atoi(argv[2]);
    // Alocando a matriz
    float **matriz = malloc(n * sizeof(float *));
    for(int i = 0; i < n; i++) {
        matriz[i] = malloc(n * sizeof(float));
        for(int j = 0; j < n; j++) {
            matriz[i][j] = (float)rand()/(float)(RAND_MAX/10);
        }
    }
    
    // Alocando o vetor
    float *vetor = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        vetor[i] = (float)rand()/(float)(RAND_MAX/10); 
    }
    
    // Alocando o vetor resultado
    float *resultado = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        resultado[i] = 0; 
    }
    
    // Multiplicando a matriz pelo vetor e calculando o tempo
    clock_t start = clock();
    if (inverter == 1){
        matriz_por_vetor_por_coluna(matriz, vetor, resultado, n);
    } else {
        matriz_por_vetor_por_linha(matriz, vetor, resultado, n);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("%f", time_spent);
    
    // Liberando a memória alocada
    for(int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vetor);
    free(resultado);
    
    return 0;
}