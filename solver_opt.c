/*
 *  * Tema 2 ASC
 *   * 2019 Spring
 *    * Catalin Olaru / Vlad Spoiala
 *     */
#include "utils.h"

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

        for (int i = 0; i < N; i++) {
                double *orig_pa = &a_trans[i * N];
                double *orig_pa_ = &b_trans[i * N];
                for (int j = i; j < N; j++) {
                        double *pa = orig_pa;
                        double *pb = &B[j];

                        double *pa_ = orig_pa_;
                        double *pb_ = &A[j];
                        register double real_sum1 = 0, real_sum2 = 0;
                        for(int k = 0; k < N; ++k) {
                                real_sum1 += *pa * *pb;
                                pa ++;
                                pb += N;

                                real_sum2 += *pa_ * *pb_;
                                pa_ ++;
                                pb_ += N;
                        }
                        res1[(i * N + j)] = real_sum1;
                        res2[(i * N + j)] = real_sum2;
                }
        }

        for(int i = 0; i < N*N; i++){
                addition[i] = res1[i] + res2[i];
        }

        for (int i = 0; i < N; i++) {
                double *orig_pa = &addition[i * N];
                for (int j = i; j < N; j++) {
                        double *pa = orig_pa;
                        double *pb = &addition[j];
                        register double real_sum = 0;
                        for(int k = 0; k < N; ++k) {
                                real_sum += *pa * *pb;
                                pa ++;
                                pb += N;
                        }
                        res[(i * N + j)] = real_sum;
                }
        }

        free(a_trans);
        free(b_trans);
        free(res1);
        free(res2);
        free(addition);
        return res;
}
