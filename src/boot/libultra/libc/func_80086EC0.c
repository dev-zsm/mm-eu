// FLAGS: -O2 -g0
#include "sdk/libc.h"

void free(void *ptr) {
    Arena_Free(&D_8009D0F0, ptr);
}
