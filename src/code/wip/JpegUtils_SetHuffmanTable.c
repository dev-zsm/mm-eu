// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 codeOffs[0x10];
    u16 codesA[0x10];
    u16 codesB[0x10];
} HT;

u16 JpegUtils_SetHuffmanTable(u8 *arg0, HT *arg1, u16 *arg2) {
    u16 idx = 0;
    u8 i = 0;
    u8 *p;
    u16 t;
    do {
        p = i + arg0;
        if (*p != 0) {
            arg1->codeOffs[i] = idx;
            arg1->codesA[i] = arg2[idx];
            t = idx + *p - 1;
            arg1->codesB[i] = arg2[t];
            idx = t + 1;
        } else {
            arg1->codesB[i] = 0xFFFF;
        }
        i++;
    } while (i < 0x10);
    return idx;
}
