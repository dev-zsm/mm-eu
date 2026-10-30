// FLAGS: -O2 -g0 -mips2
#include "libc.h"

void *realloc(void *ptr, size_t size) {
    return func_8008766C(&D_8009D0F0, ptr, size);
}
