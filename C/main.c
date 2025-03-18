#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define MAXN 2000  /* Valor máximo para N */
int N;  /* Tamanho da matriz */

/* Matrizes e vetores */
volatile float A[MAXN][MAXN], B[MAXN], X[MAXN];

/* Protótipo */
void gauss();

void parameters() {
    /* Parâmetros fixos para compiladores online */
    N = 1000;         // Tamanho da matriz para exibição dos resultados
    int seed = 1234; // Semente fixa para geração de números aleatórios
    srand(seed);
    printf("Matrix dimension N = %i.\n", N);
    printf("Random seed = %i.\n", seed);
}

void initialize_inputs() {
    int row, col;
    printf("\nInitializing...\n");
    for (col = 0; col < N; col++) {
        for (row = 0; row < N; row++) {
            A[row][col] = (float)rand() / 32768.0;
        }
        B[col] = (float)rand() / 32768.0;
        X[col] = 0.0;
    }
}

void print_inputs() {
    int row, col;
    if (N < 10) {
        printf("\nA =\n\t");
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                printf("%5.2f%s", A[row][col], (col < N-1) ? ", " : ";\n\t");
            }
        }
        printf("\nB = [");
        for (col = 0; col < N; col++) {
            printf("%5.2f%s", B[col], (col < N-1) ? "; " : "]\n");
        }
    }
}

void print_X() {
    int row;
    if (N < 100) {
        printf("\nX = [");
        for (row = 0; row < N; row++) {
            printf("%5.2f%s", X[row], (row < N-1) ? "; " : "]\n");
        }
    }
}

int main() {
    parameters();        // Define os parâmetros fixos
    initialize_inputs(); // Inicializa A e B
    print_inputs();      // Imprime as matrizes (caso N < 10)

    printf("Starting computation.\n");
    clock_t start = clock();
    gauss();             // Eliminação Gaussiana
    clock_t end = clock();
    print_X();           // Imprime o vetor resultado X

    double elapsed_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    printf("\nElapsed time = %g ms.\n", elapsed_ms);
    return 0;
}

void gauss() {
    int norm, row, col;
    float multiplier;

    printf("Computing Serially.\n");
    for (norm = 0; norm < N - 1; norm++) {
        for (row = norm + 1; row < N; row++) {
            multiplier = A[row][norm] / A[norm][norm];
            for (col = norm; col < N; col++) {
                A[row][col] -= A[norm][col] * multiplier;
            }
            B[row] -= B[norm] * multiplier;
        }
    }
    /* Substituição regressiva */
    for (row = N - 1; row >= 0; row--) {
        X[row] = B[row];
        for (col = N - 1; col > row; col--) {
            X[row] -= A[row][col] * X[col];
        }
        X[row] /= A[row][row];
    }
}