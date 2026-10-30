// FLAGS: -O2 -g0
#include "libc.h"

u8 MallocIsInitialized(void) {
    return func_8008738C(&D_8009D0F0);
}
