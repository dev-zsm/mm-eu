// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80084E40(u8 *base, u32 *hdr, u32 off) {
    u32 s5[32];
    u32 s4[32];
    u32 tbl[4];
    u32 i;
    u32 v;
    u32 w;
    u32 x;
    u32 *ptr;
    u32 *a6;
    u32 idx;
    u32 carry;
    u32 v1;

    tbl[0] = 0;
    tbl[1] = (u32)base;
    tbl[2] = (u32)base + hdr[0];
    tbl[3] = tbl[2] + hdr[1];

    i = 0;
    if (hdr[4] != 0) {
        do {
            v = hdr[5 + i];
            i++;
            ptr = (u32 *)(tbl[v >> 30] + (v & 0xFFFFFF));
            w = *ptr;

            if ((v & 0x3F000000) == 0x02000000) {
                if ((w & 0xF0000000) == 0) {
                    *ptr = (w - off) + (u32)base;
                }
            } else if ((v & 0x3F000000) == 0x04000000) {
                v1 = ((w & 0x3FFFFFF) << 2) | 0x80000000;
                *ptr = (w & 0xFC000000) | (((v1 - off + (u32)base) & 0xFFFFFFF) >> 2);
            } else if ((v & 0x3F000000) == 0x05000000) {
                s4[(w >> 16) & 0x1F] = (u32)ptr;
                s5[(w >> 16) & 0x1F] = w;
            } else if ((v & 0x3F000000) == 0x06000000) {
                idx = (w >> 21) & 0x1F;
                a6 = (u32 *)s4[idx];
                x = (u32)((s32)(w << 16) >> 16) + (s5[idx] << 16);
                if ((x & 0xF0000000) == 0) {
                    v1 = x - off + (u32)base;
                    carry = (v1 & 0x8000) ? 1 : 0;
                    *a6 = (*a6 & 0xFFFF0000) | (((v1 >> 16) & 0xFFFF) + carry);
                    *ptr = (*ptr & 0xFFFF0000) | (v1 & 0xFFFF);
                }
            }
        } while (i < hdr[4]);
    }
}
