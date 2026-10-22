// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801BA39C[];

typedef struct {
    u8 pad0[0x142];
    s16 unk142;
    s16 unk144;
    u8 pad146[6];
    s16 unk14C;
} CameraCtx;

s32 Camera_CheckValidMode(CameraCtx *arg0, s16 arg1) {
    if (arg0->unk14C & 0x20) {
        return 0;
    }
    if (!(*(u32 *)(D_801BA39C + (arg0->unk142 * 0xC)) & (1 << arg1))) {
        return 0;
    }
    if (arg1 == arg0->unk144) {
        return -1;
    }
    return arg1 | 0x80000000;
}
