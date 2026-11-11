// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 6.50 (15 differ, size +1)
#include "generated/mm/jpegutils.h"

s32 JpegUtils_GetHuffmanCodes(u8* codesLengths, u16* codes) {
    s16 idx = 0;
    u16 code = 0;
    u8 lastLen = codesLengths[0];

    while (true) {
        while (true) {
            codes[idx++] = code++;

            if (codesLengths[idx] != lastLen) {
                break;
            }
        }

        if (codesLengths[idx] == 0) {
            break;
        }

        while (true) {
            if (code <<= 1, codesLengths[idx] == ++lastLen) {
                break;
            }
        }
    }

    return idx;
}
