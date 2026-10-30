// FLAGS: -O2 -g0
#include "libc.h"

void *malloc(size_t size) {
    return func_8008743C(&D_8009D0F0, size);
}
