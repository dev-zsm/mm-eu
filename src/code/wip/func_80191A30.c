// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u8 pad0[0xA];
    s16 a;
    s16 b;
    s16 c;
} SrcEntry;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s16 h4;
    u8 pad6[0x14 - 6];
} DstEntry;

typedef struct {
    u8 pad0[0x2854];
    SrcEntry *src;
    u8 pad2858[0x2868 - 0x2858];
    DstEntry *dst;
} Tables;

extern Tables D_801F84B0;

void func_80191A30(s32 index) {
    DstEntry *dst = &D_801F84B0.dst[index];
    SrcEntry *src = &D_801F84B0.src[index];

    dst->b2 = src[1].a >> 8;
    dst->b3 = src[1].a;
    src++;
    dst->b0 = src->b >> 8;
    dst->b1 = src->b;
    dst->h4 = src->c;
}
