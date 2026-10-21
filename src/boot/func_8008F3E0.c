// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u8 D_80098000[];

typedef struct {
    u8 *begin;
    u8 *end;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Buf;

void func_8008F3E0(Buf *a0, s32 a1, s32 a2) {
    a0->begin = D_80098000;
    a0->end = D_80098000;
    a0->unk8 = 0;
    a0->unkC = 0;
    a0->unk10 = a2;
    a0->unk14 = a1;
}
