#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorts.h"

double run_sort(void (*fn)(int*,size_t,Metrics*), int *v, size_t n, Metrics *m){
    reset_metrics(m);
    clock_t t0 = clock();
    fn(v, n, m);
    clock_t t1 = clock();
    return 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;
}

int* copy_array(int *v, size_t n){
    int *r = malloc(n * sizeof(int));
    memcpy(r, v, n*sizeof(int));
    return r;
}

void print_csv(const char *metodo, int N, const char *caso, Metrics m, double t){
    printf("%s,%d,%s,%lld,%lld,%.4f\n",
        metodo, N, caso, m.cmp, m.swp, t);
}

void run_all(const char *caso, int *v, size_t n){
    Metrics m;
    int *tmp;

    tmp = copy_array(v,n);
    double t = run_sort(insertion_sort, tmp, n, &m);
    print_csv("insertion", n, caso, m, t);
    free(tmp);

    tmp = copy_array(v,n);
    t = run_sort(merge_sort, tmp, n, &m);
    print_csv("merge", n, caso, m, t);
    free(tmp);

    tmp = copy_array(v,n);
    t = run_sort(quick_sort, tmp, n, &m);
    print_csv("quick", n, caso, m, t);
    free(tmp);
}

int main() {

    char rgm_str[32];
    printf("Digite seu RGM: ");
    scanf("%s", rgm_str);

    size_t n_rgm = strlen(rgm_str);
    int *rgm = malloc(n_rgm * sizeof(int));
    for (size_t i = 0; i < n_rgm; i++)
        rgm[i] = rgm_str[i] - '0';

    printf("\nmetodo,N,caso,comparacoes,trocas,tempo_ms\n");

    run_all("rgm", rgm, n_rgm);

    int sizes[] = {100, 1000, 10000};

    for (int s = 0; s < 3; s++) {
        int N = sizes[s];
        int *v = malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            v[i] = rand() % 1000;

        run_all("aleatorio", v, N);

        free(v);
    }

    free(rgm);
    return 0;
}
