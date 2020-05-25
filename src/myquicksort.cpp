
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

int achar_mediana(std::vector<int> &v){

    int tam = sizeof(v)/4; 
    std::vector<int> vmed(3);
    vmed[0] = v[0];
    vmed[1] = v[tam/2];
    vmed[2] = v[tam - 1];

    int min = vmed[0];
    int max = vmed[0];
    int i = 0;
    int mediana;

    for (i = 1; i < 3; i++){
        if (vmed[i] >= max)
            max = vmed[i];
        if (vmed[i] <= min)
            min = vmed[i];
    }

    for (i = 0; i < 3; i++){
        if (vmed[i] != max && vmed[i] != min)
            mediana = vmed[i];
    }

    return mediana;

}

int Partition_mediana(std::vector<int> &v){

    int mediana = achar_mediana(v);

    int tam = sizeof(v)/4;
    int pivo = v[mediana];
    int L = tam;
    int R = 0;

    while (true){

        while (L < 0 && v[L] < pivo)
            L++;
        
        while (R > tam && v[R] >= pivo)
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

int Partition_fixo(std::vector<int> &v){

    int tam = sizeof(v)/4;
    int pivo = v[0];
    int L = tam;
    int R = 0;

    while (true){

        while (L < 0 && v[L] < pivo)
            L++;
        
        while (R > tam && v[R] >= pivo)
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
    int min = 0;
    int max = tam - 1;
    int i = 0;
    int p;

    int m = achar_mediana(v);

    std::vector<int> v1(m + 1);
    std::vector<int> v2(tam - m -1);

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    if (min < max){
        p = Partition_mediana (v);
        myquicksort_2recursion_medianOf3 (v1, stats);
        myquicksort_2recursion_medianOf3 (v2, stats);
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
    int min = 0;
    int max = tam - 1;
    int i = 0;
    int p;

    int m = achar_mediana(v);

    std::vector<int> v1(m + 1);
    std::vector<int> v2(tam - m -1);

    for (i = 0; i <= m; i++)
        v1[i] = v[i];
    
    for (i = m + 1; i < tam; i++)
        v2[i - m - 1] = v[i];

    while (min < max){

        p = Partition_mediana (v);

        if (p - min < max - p){
            myquicksort_1recursion_medianOf3(v1, stats);
            min = p + 1;
        }

        else{
            myquicksort_1recursion_medianOf3(v2, stats);
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
    int min = 0;
    int max = tam - 1;
    int i = 0;
    int p;

    if (min < max){
        p = Partition_fixo (v);

        std::vector<int> v1(p + 1);
        std::vector<int> v2(tam - p -1);

        for (i = 0; i <= p; i++)
            v1[i] = v[i];
        
        for (i = p + 1; i < tam; i++)
            v2[i - p - 1] = v[i];

        myquicksort_2recursion_medianOf3 (v1, stats);
        myquicksort_2recursion_medianOf3 (v2, stats);
    }

} // myquicksort_fixedPivot
