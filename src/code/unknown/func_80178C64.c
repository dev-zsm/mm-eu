// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    u16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Struct80178C64;

void func_80178C64(Struct80178C64 *arg0, s32 arg1, s32 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk8 = arg3;
    arg0->unkA = arg4;
    arg0->unkC = arg5;
    arg0->unk10 = arg6;
    arg0->unk14 = arg7;
    arg0->unk18 = arg8;
}
