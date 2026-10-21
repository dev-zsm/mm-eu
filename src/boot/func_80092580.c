// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[0xC];
    s32 unk10;
    s32 unk14;
} Struct800982B4;

extern Struct800982B4 *D_800982B4;

s32 func_80091C00(void);
void func_80091C70(s32 a);

void func_80092580(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;

    temp_a0 = func_80091C00();
    D_800982B4->unk10 = arg0;
    D_800982B4->unk14 = arg1;
    D_800982B4->unk2 = arg2;
    func_80091C70(temp_a0);
}
