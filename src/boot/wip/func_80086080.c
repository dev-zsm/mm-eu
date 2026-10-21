// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    void *unk0;
    s32 unk4;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
    u8 unkF;
    s32 unk10;
} Obj;

s32 func_80086054(s32 arg0, u8 *arg1, s32 arg2);

void func_80086080(Obj *arg0) {
    u8 t9; u8 t1; u8 t3; u8 t5; u8 t6;
    t6 = arg0->unkF;
    t9 = t6 & 0xFF7F;
    *(volatile u8 *)&arg0->unkF = t9;
    t1 = t9 & 0xFFFE;
    *(volatile u8 *)&arg0->unkF = t1;
    t3 = t1 & 0xFFFD;
    *(volatile u8 *)&arg0->unkF = t3;
    t5 = t3 | 4;
    *(volatile u8 *)&arg0->unkF = t5;
    arg0->unk0 = (void *) func_80086054;
    arg0->unk4 = 0; arg0->unk8 = 0; arg0->unkA = 0; arg0->unkC = 0; arg0->unkE = 0; arg0->unk10 = 0;
    arg0->unkF = (u8) (t5 | 8);
}
