// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/yaz0_ctx.h"

extern char D_800984A0[];

void* Yaz0_NextDMA(u8* curSrcPos) {
    u8* dst;
    size_t restSize;
    size_t dmaSize;
    OSPri oldPri;

    restSize = sYaz0DataBufferEnd - curSrcPos;
    dst = (restSize & 7) ? (sYaz0DataBuffer - (restSize & 7)) + 8 : sYaz0DataBuffer;

    bcopy(curSrcPos, dst, restSize);
    dmaSize = sYaz0DataBufferEnd - dst - restSize;
    if (sYaz0CurSize < dmaSize) {
        dmaSize = sYaz0CurSize;
    }

    if (dmaSize != 0) {
        DmaMgr_DmaRomToRam(sYaz0CurRomStart, dst + restSize, dmaSize);
        sYaz0CurRomStart += dmaSize;
        sYaz0CurSize -= dmaSize;
        if (sYaz0CurSize == 0) {
            sYaz0MaxPtr = dst + restSize + dmaSize;
        }
    } else {
        oldPri = osGetThreadPri(NULL);
        osSetThreadPri(NULL, OS_PRIORITY_APPMAX);
        osSyncPrintf(D_800984A0);
        osSetThreadPri(NULL, oldPri);
    }

    return dst;
}
