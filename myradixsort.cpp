
#include <mysortfunctions.h>
#include <math.h>
#include <queue>

void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    int bits = log2(v.size());
    if (2^bits < v.size())
        bits += 1;
    
    int d = log2(bits);
    if (2^d < bits)
        d += 1;

    std::queue <int> fila[1 << 4];
    int mascara = (1 << 4) - 1;
    int i, j, k = 0;
    
    for (i = 0; i < d; i++) {
        for (j = 0; j < (int) v.size(); j++) {

            if (i == 0) 
                fila[v[j] & mascara].push(v[j]);

            else 
                fila[(v[j] >> (i * 4)) & mascara].push(v[j]);
        }
        
        for (j = 0, k = 0; j < (1 << 4); j++)
            while (!fila[j].empty()) {
                v[k++] = fila[j].front();
                fila[j].pop();
                stats.recursive_calls += 1;
            }

    }

    stats.depth_recursion_stack = (int)(log2(stats.recursive_calls + 1));

}
