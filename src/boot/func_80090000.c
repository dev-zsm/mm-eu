// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[2];
    s32 unk4;
} BootObj;

extern BootObj *D_800982B4;
s32 func_80091C00(void);
void func_80091C70(s32, BootObj **);

void func_80090000(s32 arg0) {
    s32 temp_a0;

    temp_a0 = func_80091C00();
    D_800982B4->unk4 = arg0;
    D_800982B4->unk0 = (u16)(D_800982B4->unk0 | 0x10);
    func_80091C70(temp_a0, &D_800982B4);
}
