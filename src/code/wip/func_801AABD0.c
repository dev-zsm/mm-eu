// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 6.00 (8 differ, size +1)
#include "generated/mm/jpegutils.h"

u32 JpegUtils_ProcessHuffmanTableImpl(u8* data, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 isAc) {
    s16 ret;
    s32 count = JpegUtils_ParseHuffmanCodesLengths(data, codesLengths);
    s32 temp;

    ret = count;
    if ((count == 0) || (isAc && (count > 0x100)) || (!isAc && (count > 0x10))) {
        return 0;
    }
    if (ret != JpegUtils_GetHuffmanCodes(codesLengths, codes)) {
        return 0;
    }
    if (temp = JpegUtils_SetHuffmanTable(data, ht, codes), temp != ret) {
        return 0;
    }

    return ret;
}
