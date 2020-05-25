
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

int Partition_mediana(int left, int right){

    int mediana = achar_mediana(v);

    int pivo = v[mediana];
    int L = left + 1;
    int R = right;

    while (true){

        while (L < right && v[L] < pivo)
            L++;
        
        while (R > left && v[R] >= pivo)
            R--;

        if (L >= R)
            break;

        aux = v[L];
        v[L] = v[R];
        v[R] = aux;
    }

    v[left] = v[R];
    v[R] = pivo;

    return r;

}

int Partition_fixo(int left, int right){

    int pivo = v[left];
    int L = left + 1;
    int R = right;

    while (true){

        while (L < right && v[L] < pivo)
            L++;
        
        while (R > left && v[R] >= pivo)
            R--;

        if (L >= R)
            break;

        aux = v[L];
        v[L] = v[R];
        v[R] = aux;
    }

    v[left] = v[R];
    v[R] = pivo;

    return r;

}

int achar_mediana(std::vector<int> &v){

    int tam = sizeof(v)/4; 
    int vmed[3];
    vmed[0] = v[0];
    vmed[1] = v[tam/2];
    vmed[2] = v[tam - 1];

    int min = int max = vmed[0];

    for (i = 1; i < 3; i++){
        if vmed[i] > max
            max = vmed[i];
        if vmed[i] < min
            min = vmed[i];
    }

    for (i = 0; i < 3; i++){
        if vmed[i] != max && vmed[i] != min
            int mediana = vmed[i];
    }


    return mediana;

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

    int tam = sizeof(v)/4;
    int min;
    int max = tam - 1;

    int v1[m + 1];
    int v2[tam - m - 1];

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    if (min < max){
        p = Partition_mediana (min, max);
        myquicksort_2recursion_medianOf3 (v1);
        myquicksort_2recursion_medianOf3 (v2);
    }

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

    int tam = sizeof(v)/4;
    int min;
    int max = tam - 1;

    int v1[m + 1];
    int v2[tam - m - 1];

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    while (min < max){

        p = Partition_mediana (min, max);

        if (p - min < max - p){
            myquicksort_1recursion_medianOf3(min, p - 1);
            min = p + 1;
        }

        else{
            myquicksort_1recursion_medianOf3(p + 1, max);
            min = p - 1;
        }
    }

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

    int tam = sizeof(v)/4;
    int min;
    int max = tam - 1;

    int v1[m + 1];
    int v2[tam - m - 1];

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    if (min < max){
        p = Partition_fixo (min, max);
        myquicksort_2recursion_medianOf3 (v1);
        myquicksort_2recursion_medianOf3 (v2);
    }

} // myquicksort_fixedPivot
