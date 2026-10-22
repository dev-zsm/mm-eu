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

s32 GfxPrint_Close(Obj *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    arg0->unk4 = 0;
    arg0->unkF = arg0->unkF & 0xFF7F;
    return temp_v0;
}
