// FLAGS: -O2 -g0
#include "libc.h"

void *calloc(size_t count, size_t size) {
    void *ptr;
    size_t total = count * size;

    ptr = func_8008743C(&D_8009D0F0, total);
    if (ptr != NULL) {
        bzero(ptr, total);
    }
    return ptr;
}
