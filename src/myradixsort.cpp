
#include <mysortfunctions.h>


void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    queue q[0..base-1];
    for (i=0, factor = 1; i < d; factor *= base, i++) {

        for (j = 1; j <= n; j++)
            q[(v[j]/factor) % base].enqueue(v[j]);

        for (j = 0, k=1; j < base; j++)
            while (!q[j].isEmpty())
                v[k++] = q[j].dequeue();
    }

}
