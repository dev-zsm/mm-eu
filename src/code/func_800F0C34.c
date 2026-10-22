// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[4]; s32 unk4; u8 pad1[0x6C]; f32 unk74; u8 pad2[0x1E8 - 0x78]; s16 unk1E8; } EnHy;

void EnHy_ChangeObjectAndAnim(f32, s32, s16);

s32 EnHy_SetPointFowards(EnHy *arg0, s32 arg1, f32 arg2, s16 arg3) {
    arg0->unk74 = arg2;
    arg0->unk4 = arg0->unk4 | 1;
    EnHy_ChangeObjectAndAnim(arg2, arg1, arg3);
    arg0->unk1E8 = arg0->unk1E8 + 1;
    return 0;
}
