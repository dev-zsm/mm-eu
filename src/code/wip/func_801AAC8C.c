// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 15.00 (55 differ, size +2)
#include "generated/mm/jpegutils.h"

u32 JpegUtils_ProcessHuffmanTable(u8* dht, JpegHuffmanTable* ht, u8* codesLengths, u16* codes, u8 count) {
    u8 idx;
    u32 codeCount;

    for (idx = 0; idx < count; idx++) {
        u32 ac = (*dht++ >> 4);

        codeCount = JpegUtils_ProcessHuffmanTableImpl(dht, &ht[idx], codesLengths, codes, ac);
        if (codeCount == 0) {
            return true;
        }

        dht += 16;
        ht[idx].symbols = dht;
        dht += codeCount;
    }
    return false;
}
