// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x208];
    /* 0x208 */ u16 unk208;
} Ea;

void func_8018132C(f32, f32, f32, s32);

s32 func_800008EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, Ea *arg5) {
    f32 y;

    if (arg1 == 2) {
        if (arg5->unk208 & 0x40) {
            y = -100.0f;
        } else {
            y = 0.0f;
        }
        func_8018132C(0.0f, y, 0.0f, 1);
    }
    return 0;
}
