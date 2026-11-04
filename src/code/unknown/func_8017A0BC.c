// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_cmpdma.h"

void CmpDma_LoadFile(uintptr_t segmentVrom, s32 id, void* dst, size_t size) {
    CmpDma_LoadFileImpl(DmaMgr_TranslateVromToRom(segmentVrom), id, dst, size);
}
