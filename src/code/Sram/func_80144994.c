// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_sram_NES.h"

u16 Sram_CalcChecksum(void* data, size_t count) {
    u8* dataPtr = data;
    u16 chkSum = 0;

    while (count-- > 0) {
        chkSum += *dataPtr;
        dataPtr++;
    }
    return chkSum;
}
