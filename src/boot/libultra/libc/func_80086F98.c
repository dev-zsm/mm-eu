// FLAGS: -O2 -g0 -mips2
#include "sdk/libc.h"

void MallocInit(void *start, size_t size) {
    __osMallocInit(&D_8009D0F0, start, size);
}
