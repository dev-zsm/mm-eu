// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

void JpegUtils_SetHuffmanTableOld(u8 *codeOffs, u8 *dst, u8 *vals, u16 *codes, s16 count, u8 flag) {
    s16 i;
    u8 idx;

    for (i = 0; i < count; i = i + 1) {
        idx = codeOffs[i];
        if (flag) {
            ((u16 *)(dst + 0x100))[idx] = codes[i];
            dst[idx] = vals[i];
        } else {
            ((u16 *)(dst + 0x10))[idx] = codes[i];
            dst[idx] = vals[i];
        }
    }
}
