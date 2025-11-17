#include "sorts.h"
#include <stdlib.h>

#define CMP(m)  ((m)->cmp++)
#define SWP(m)  ((m)->swp++)

void reset_metrics(Metrics *m) {
    m->cmp = 0;
    m->swp = 0;
}

//insertionsort
void insertion_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 1; i < n; i++) {
        int key = v[i];
        size_t j = i;

        while (j > 0 && (CMP(m), v[j-1] > key)) {
            v[j] = v[j-1];
            SWP(m);
            j--;
        }
        v[j] = key;
        SWP(m);
    }
}

//merge sort
static void merge(int *v, int *tmp, size_t left, size_t mid, size_t right, Metrics *m) {
    size_t i = left, j = mid+1, k = left;

    while (i <= mid && j <= right) {
        CMP(m);
        if (v[i] <= v[j]) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
        SWP(m);
    }

    while (i <= mid) { tmp[k++] = v[i++]; SWP(m); }
    while (j <= right){ tmp[k++] = v[j++]; SWP(m); }

    for (size_t p = left; p <= right; p++){
        v[p] = tmp[p];
        SWP(m);
    }
}

static void merge_sort_rec(int *v, int *tmp, size_t left, size_t right, Metrics *m) {
    if (left >= right) return;
    size_t mid = (left + right) / 2;
    merge_sort_rec(v, tmp, left, mid, m);
    merge_sort_rec(v, tmp, mid+1, right, m);
    merge(v, tmp, left, mid, right, m);
}

void merge_sort(int *v, size_t n, Metrics *m) {
    int *tmp = malloc(n * sizeof(int));
    merge_sort_rec(v, tmp, 0, n-1, m);
    free(tmp);
}

//quicksort
  
static size_t lomuto(int *v, size_t low, size_t high, Metrics *m) {
    int p = v[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        CMP(m);
        if (v[j] < p) {
            int t = v[i]; v[i] = v[j]; v[j] = t;
            SWP(m);
            i++;
        }
    }
    int t = v[i]; v[i] = v[high]; v[high] = t;
    SWP(m);
    return i;
}

static void quick_rec(int *v, size_t low, size_t high, Metrics *m) {
    if (low < high) {
        size_t p = lomuto(v, low, high, m);
        if (p > 0) quick_rec(v, low, p-1, m);
        quick_rec(v, p+1, high, m);
    }
}

void quick_sort(int *v, size_t n, Metrics *m) {
    quick_rec(v, 0, n-1, m);
}
