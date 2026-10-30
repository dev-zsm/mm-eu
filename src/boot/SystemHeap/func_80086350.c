#include "systemheap.h"

void *SystemHeap_Malloc(size_t size) {
    size_t n = size;

    if (size == 0) {
        n = 1;
    }
    return func_8008743C(&D_8009D0F0, n);
}
