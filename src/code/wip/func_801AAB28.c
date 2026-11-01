#include "types.h"

typedef struct {
    u8 a[0x10];
    u16 b[0x10];
    u16 c[0x10];
} HuffOut;

s32 JpegUtils_SetHuffmanTable(u8 *counts, HuffOut *out, u16 *codes) {
    s32 idx = 0;
    u8 i;

    for (i = 0; i < 0x10; i++) {
        if (counts[i] != 0) {
            out->a[i] = idx;
            out->b[i] = codes[idx];
            idx += counts[i] - 1;
            out->c[i] = codes[(u16)idx];
            idx = (u16)((u16)idx + 1);
        } else {
            out->c[i] = 0xFFFF;
        }

    }
    return idx;
}
