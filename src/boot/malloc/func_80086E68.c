// FLAGS: -O2 -g0
#include "sdk/libc.h"

void *malloc_r(size_t size) {
    return func_8008747C(&D_8009D0F0, size);
}
