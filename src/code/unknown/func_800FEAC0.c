// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lib.h"

void* Lib_MemSet(void* buffer, s32 value, size_t size) {
    u8* v0;
    s32 i;

    if (value == 0) {
        bzero(buffer, size);

        return buffer;
    }

    for (v0 = (u8*)buffer, i = size; i > 0; i--) {
        *v0++ = value;
    }

    return buffer;
}
