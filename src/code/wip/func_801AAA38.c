// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 JpegUtils_ParseHuffmanCodesLengths(u8 *ptr, u8 *codesLengths) {
    u8 i = 1;
    s16 idx = 0;
    s16 count = 1;
    u8 k = 1;

    while (k < 17) {
        if (ptr[k - 1] > 0) {
            do {
                codesLengths[idx++] = i;
                count++;
            } while (ptr[k - 1] >= count);
            count = 1;
        }
        i++;
        k = i;
    }
    codesLengths[idx] = 0;
    return idx;
}
