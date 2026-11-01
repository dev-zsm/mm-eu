#include "types.h"

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 padE[2];
    u32 unk10;
    u8 pad14[0x30];
} Ent;

typedef struct {
    u8 pad0[8];
    u8 count;
    u8 count2;
    u8 padA[2];
} Hdr;

typedef struct {
    u32 start;
    u32 end;
} Range;

extern Range D_801C3400[];
extern void func_80080CE0();

s32 func_8012F680(Ent *a0, s16 a1) {
    Hdr *h = (Hdr *)a0;
    u32 start;
    s32 size;

    a0[h->count].unkC = a1;
    size = D_801C3400[a1].end;
    start = D_801C3400[a1].start;
    size -= start;
    if (size != 0) {
        func_80080CE0(a0[h->count].unk10, start, size, a0);
    }
    if (h->count < 0x22) {
        a0[h->count + 1].unk10 = (a0[h->count].unk10 + size + 0xF) & ~0xF;
    }
    h->count2 = ++h->count;
    return h->count2 - 1;
}
