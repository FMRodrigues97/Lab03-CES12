#ifndef YOURSORTFUNCTIONS_H
#define YOURSORTFUNCTIONS_H


#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <sortauxfuncs.h>

void merge(std::vector<int> &v, std::vector<int> &aux, int inicio, int meio, int fim);
void MergeSortRecursivo(std::vector<int> &v, std::vector<int> &aux, int inicio, int fim, SortStats &stats);
void MergeSortIterativo(std::vector<int> &v, std::vector<int> &aux, int inicio, int fim);

int Partition_mediana(std::vector<int> &v, int esquerda, int direita);
int Partition_fixo(std::vector<int> &v, int esquerda, int direita);
void QuickSort2 (std::vector<int> &v, int min, int max, SortStats &stats);
void QuickSort1 (std::vector<int> &v, int min, int max, SortStats &stats);
void QuickSortPivo (std::vector<int> &v, int min, int max, SortStats &stats);

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats);

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats);

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats);

/// how to implement Radix Sort on integers
/// the max value is known (it is the size of the vector)
/// thus, we know how many bits the number has
/// select bits using a bit mask e.g. ( x & 0xF00 )
/// will select 4 bits. After shifting the bits right with the >> operator,
/// you get a 4-bit value between 0 and 15, which you use to index the right queue.
/// this is much faster than performing integer / and % to select decimal digits
/// it is a computer, think in binary. Obviously if you select 3 bits instead of 4
/// you will have 8 queues instead of 16, and so on. I do not know what is better.
void myradixsort(std::vector<int> &v, SortStats &stats);

void mymergesort_recursive(std::vector<int> &v, SortStats &stats);

void mymergesort_iterative(std::vector<int> &v, SortStats &stats);

#endif
