// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x14E];
    s16 f14E;
    u8 pad150[0x12];
    s16 f162;
} Inner;

extern void Play_ClearCamera(void *ctx, s16 idx);
extern void Play_ChangeCameraStatus(void *ctx, s32 a, s32 b);

void func_8016AC6C(u8 *ctx, s16 a1, s16 a2) {
    s32 i;
    s16 x;

    if (a1 == -1) {
        x = *(s16 *)(ctx + 0x810);
    } else {
        x = a1;
    }
    if (x != 0) {
        Play_ClearCamera(ctx, x);
    } else {
        a2 = 0;
    }
    for (i = 1; i != 4; i++) {
        if (*(s32 *)(ctx + 0x800 + i * 4) != 0) {
            Play_ClearCamera(ctx, i);
        }
    }
    if (a2 <= 0) {
        Play_ChangeCameraStatus(ctx, 0, 7);
        (*(Inner **)(ctx + 0x800))->f162 = 0;
        (*(Inner **)(ctx + 0x800))->f14E = (*(Inner **)(ctx + 0x800))->f162;
    }
}
