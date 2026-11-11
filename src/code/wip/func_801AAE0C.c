// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 10.00 (16 differ, size +1)
#include "generated/mm/jpegutils.h"

u32 JpegUtils_ProcessHuffmanTableImplOld(u8* dht, JpegHuffmanTableOld* ht, u8* codesLengths, u16* codes) {
    u8 isAc = *dht++ >> 4;
    s16 count2;
    s32 count;

    count2 = count = JpegUtils_ParseHuffmanCodesLengths(dht, codesLengths);

    if ((count == 0) || (isAc && (count > 0x100)) || (!isAc && (count > 0x10))) {
        return true;
    }

    if (JpegUtils_GetHuffmanCodes(codesLengths, codes) != count2) {
        return true;
    }

    JpegUtils_SetHuffmanTableOld(dht + 0x10, ht, codesLengths, codes, count2, isAc);

    return false;
}
