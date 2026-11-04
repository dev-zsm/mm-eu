// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_jpeg.h"

u16 Jpeg_GetUnalignedU16(u8* ptr) {
    if (((uintptr_t)ptr & 1) == 0) {
        
        return *(u16*)ptr;
    } else {
        
        return *(u16*)(ptr - 1) << 8 | (*(u16*)(ptr + 1) >> 8);
    }
}
