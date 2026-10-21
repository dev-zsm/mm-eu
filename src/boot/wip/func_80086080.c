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
    arg0->unkF &= ~0x80;
    arg0->unkF &= ~1;
    arg0->unkF &= ~2;
    arg0->unkF |= 4;
    arg0->unk0 = (void *) func_80086054;
    arg0->unk4 = 0; arg0->unk8 = 0; arg0->unkA = 0; arg0->unkC = 0; arg0->unkE = 0; arg0->unk10 = 0;
    arg0->unkF |= 8;
}
