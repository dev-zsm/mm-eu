// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1[0x1F];
    s32 unk20;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
} MorphArg;

extern void AnimTaskQueue_AddInterp(void *, s32, s32, s32, f32);
extern void PlayerAnimation_SetUpdateFunction(MorphArg *);

// ROM keeps the pre-update value in its own register, needs the separate temp.
s32 PlayerAnimation_Morph(u8 *play, MorphArg *arg) {
    f32 prev;
    f32 speed;

    speed = (s32)play[0xA2] * 0.5f;
    prev = arg->unk28;
    arg->unk28 = arg->unk28 - arg->unk2C * speed;
    if (arg->unk28 <= 0.0f) {
        PlayerAnimation_SetUpdateFunction(arg);
    }
    AnimTaskQueue_AddInterp(play, arg->unk0, arg->unk20, arg->unk24, 1.0f - arg->unk28 / prev);
    return 0;
}
