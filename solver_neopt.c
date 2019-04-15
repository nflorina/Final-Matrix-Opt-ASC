/*
 *  * Tema 2 ASC
 *   * 2019 Spring
 *    * Catalin Olaru / Vlad Spoiala
 *     */
#include "utils.h"

/*
 *  * Add your unoptimized implementation here
 *   */
double* my_solver(int N, double *A, double* B) {
    double *res1 = malloc(N*N*sizeof(double));
    double *res2 = malloc(N*N*sizeof(double));
    double *addition = malloc(N*N*sizeof(double));
    double *res = malloc(N*N*sizeof(double));
    double *a_trans = malloc(N*N*(sizeof(double)));
    double *b_trans = malloc(N*N*(sizeof(double)));
    printf("NEOPT SOLVER\n");

    for(int i = 0; i < N*N; i++){
            a_trans[N*(i%N) + (i/N)] = A[i];
            b_trans[N*(i%N) + (i/N)] = B[i];
    }
    for (int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            double suma1 = 0, suma2 = 0;
            for(int j = 0; j < N; j++) {
                suma1 += a_trans[(k * N) + j] * B[(j * N) + i];
                suma2 += b_trans[(k * N) + j] * A[(j * N) + i];
            }
            res1[(k * N) + i] = suma1;
            res2[(k * N) + i] = suma2;

        }
    }

    for(int i = 0; i < N*N; i++){
            if (i/N > i%N)
                    addition[i] = 0;
            else
                    addition[i] = res1[i] + res2[i];
    }

    for (int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            double suma = 0;
            for(int j = 0; j < N; j++) {
                suma += addition[(k * N) + j] * addition[(j * N) + i];
            }
                res[(k * N) + i] = suma;
        }
    }
    free(res1);
    free(res2);
    free(addition);
    free(a_trans);
    free(b_trans);

    return res;
}
