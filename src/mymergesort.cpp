
#include <mysortfunctions.h>

void merge(std::vector<int> &v, std::vector<int> &aux){

    int tam = sizeof(v)/4;
    int i = 0;
    int j = 0;
    int f = tam - 1;
    int m = (tam)/2 - 1;

    int i1 = i;
    int i2 = i;
    int i3 = m + 1;

    while (i2 <= m && i3 <= f){

        if (v[i2] < v[i3])
            aux[i1++] = v[i2++];

        else
            aux[i1++] = v[i3++];
    }

    while (i2 <= m)
        aux[i1++] = v[i2++];
    
    while (i3 <= m)
        aux[i1++] = v[i3++];

    for (j = i; j<=f; j++)
        v[j] = aux[j];

}


void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    
    int tam = sizeof(v)/4;
    int i;
    int f = tam - 1;
    int m = (tam)/2 - 1;

    int aux[tam];
    int v1[m + 1];
    int v2[tam - m - 1];

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    i = 0;
    if (i < f){
        mymergesort_recursive(v1, stats);
        mymergesort_recursive(v2, stats);
        merge(v, aux);
    }

}


void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int tam = sizeof(v)/4;
    int i = 0;
    int f = tam - 1;
    int aux[tam];
    int m = (tam)/2 - 1;

    int b = 1; // b: tamanho de cada bloco 
    while (b < f){
        int p = i;
        while (p + b <= f){

            int r = f;
            if (f > p-1 + 2*b)
                r = p-1 + 2*b;

            m = p + b - 1;
            merge (p, m, r);
            p += 2*b;
        }

        b *= 2;
    }

}
