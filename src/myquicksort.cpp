
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

int Partition_mediana(std::vector<int> &v, int esquerda, int direita){

    // Achar a mediana
    int tam = v.size();

    if ( (v[0] >= v[tam/2] && v[0] <= v[tam - 1]) || (v[0] <= v[tam/2] && v[0] >= v[tam - 1]) )
        mediana = 0;
    
    if ( (v[tam/2] >= v[0] && v[tam/2] <= v[tam - 1]) || (v[tam/2] <= v[0] && v[tam/2] >= v[tam - 1]) )
        mediana = tam/2;

    if ( (v[tam -1] >= v[0] && v[tam - 1] <= v[tam/2]) || (v[tam -1] <= v[0] && v[tam - 1] >= v[tam/2]) )
        mediana = tam - 1;
    
    
    int pivo = v[mediana];
    int L = esquerda + 1;
    int R = direita;

    while (true){

        while (L < direita && v[L] < pivo)
            L++;
        
        while (R > esquerda && v[R] >= pivo)
            R--;

        if (L >= R)
            break;

        int aux = v[L];
        v[L] = v[R];
        v[R] = aux;
    }

    v[esquerda] = v[R];
    v[R] = pivo;

    return R;

}

int Partition_fixo(std::vector<int> &v, int esquerda, int direita){

    int tam = v.size();
    int pivo = v[esquerda];
    int L = esquerda + 1;
    int R = direita;

    while (true){

        while (L < direita && v[L] < pivo)
            L++;
        
        while (R > esquerda && v[R] >= pivo)
            R--;

        if (L >= R)
            break;

        int aux = v[L];
        v[L] = v[R];
        v[R] = aux;
    }

    v[tam] = v[R];
    v[R] = pivo;

    return R;

}

void QuickSort2 (std::vector<int> &v, int min, int max){

    if (min < max){
        int p = Partition_mediana (v, min, max);
        QuickSort2 (v, min, p - 1);
        QuickSort2 (v, p + 1, max);
    }

}

void QuickSort1 (std::vector<int> &v, int min, int max){

    while (min < max){

        int p = Partition_mediana (v, min, max);

        if (p - min < max - p){
            QuickSort1 (v, min, p - 1);
            min = p + 1;
        }

        else{
            QuickSort1 (v, p + 1, max);
            max = p - 1;
        }
    }
}

void QuickSortPivo (std::vector<int> &v, int min, int max){

    while (min < max){

        int p = Partition_fixo (v, min, max);

        if (p - min < max - p){
            QuickSortPivo (v, min, p - 1);
            min = p + 1;
        }

        else{
            QuickSortPivo (v, p + 1, max);
            max = p - 1;
        }
    }
}

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int tam = v.size();
    int min = 0;
    int max = tam - 1;

    QuickSort2 (v, min, max);

}// function myquicksort_2recursion_medianOf3

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int tam = v.size();
    int min = 0;
    int max = tam - 1;

    QuickSort1 (v, min, max);

} // function myquicksort_1recursion_medianOf3

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int tam = v.size();
    int min = 0;
    int max = tam - 1;

    QuickSortPivo (v, min, max);

} // myquicksort_fixedPivot
