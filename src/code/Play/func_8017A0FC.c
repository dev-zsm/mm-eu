// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_cmpdma.h"

void CmpDma_LoadAllFiles(uintptr_t segmentVrom, void* dst, size_t size) {
    uintptr_t rom = DmaMgr_TranslateVromToRom(segmentVrom);
    u32 i;
    u32 end;
    void* nextDst;
    u32 dataStart;

    DmaMgr_DmaRomToRam(rom, &sDmaBuffer.dataStart, sizeof(sDmaBuffer.dataStart));

    dataStart = sDmaBuffer.dataStart;
    nextDst = dst;
    end = (dataStart / sizeof(u32)) - 1;

    for (i = 0; i < end; i++) {
        CmpDma_LoadFileImpl(rom, i, nextDst, 0);
        nextDst = gYaz0DecompressDstEnd;
    }
}
