/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include <cblas.h>
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
        printf("BLAS SOLVER\n");

        double *left = malloc(N*N*sizeof(double));
        if(left == NULL) {
                perror("Error on malloc!\n");
                exit(-1);
        }
        double *res = malloc(N*N*sizeof(double));
        if(res == NULL) {
                perror("Error on malloc!\n");
                exit(-1);
        }
        cblas_dgemm(CblasRowMajor,CblasTrans,CblasNoTrans,
           N, N, N, 1.0, A, N, B, N, 0.0, left, N);
        cblas_dgemm(CblasRowMajor,CblasTrans,CblasNoTrans,
           N, N, N, 1.0, B, N, A, N, 1.0, left, N);

        for(int i = 0; i < N*N; i++){
                if (i/N > i%N)
                        left[i] = 0;
        }
        cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,
           N, N, N, 1.0, left, N, left, N, 0.0, res, N);

        free(left);
        return res;
}