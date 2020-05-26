
#include <mysortfunctions.h>

void merge(std::vector<int> &v, std::vector<int> &aux, int inicio, int meio, int fim){

    int i1 = inicio;
    int i2 = inicio;
    int i3 = meio + 1;

    while (i2 <= meio && i3 <= fim){

        if (v[i2] < v[i3]){
            aux[i1++] = v[i2++];
        }
        else{
            aux[i1++] = v[i3++];
        }
    }

    while (i2 <= meio){
        aux[i1++] = v[i2++];
    }
    
    while (i3 <= fim){
        aux[i1++] = v[i3++];
    }

    for (int j = inicio; j <= fim; j++){
        v[j] = aux[j];
    }

}

void MergeSortRecursivo(std::vector<int> &v, std::vector<int> &aux, int inicio, int fim){

    if (inicio < fim){

        int meio = (inicio + fim)/2;
        MergeSortRecursivo(v, aux, inicio, meio);
        MergeSortRecursivo(v, aux, meio + 1, fim);
        merge(v, aux, inicio, meio, fim);

    }    
}

void MergeSortIterativo(std::vector<int> &v, std::vector<int> &aux, int inicio, int fim){

    int b = 1; // b: tamanho de cada bloco 

    while (b < fim){

        int p = inicio;

        while (p + b <= fim){

            int r = fim;
            if (fim > p-1 + 2*b)
                r = p - 1 + 2*b;

            int meio = p + b - 1;
            merge(v, aux, p, meio, r);
            p += 2*b;
        }

        b *= 2;
    }
}

void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    
    int tam = v.size();
    int inicio = 0;
    int fim = tam - 1;

    std::vector<int> aux(tam);

    MergeSortRecursivo(v, aux, inicio, fim);

}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int tam = v.size();
    int inicio = 0;
    int fim = tam - 1;
    
    std::vector<int> aux(tam);

    MergeSortIterativo(v, aux, inicio, fim);

}
