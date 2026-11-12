// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_flashrom_ctx.h"

s32 SysFlashrom_EraseSector(u32 page) {
    if (!SysFlashrom_IsInit()) {
        return -1;
    }
    return osFlashSectorErase(page);
}
