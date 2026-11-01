#include "types.h"

typedef struct {
    u8 unk0[0xC];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
} EffectParams;

extern void Math_Vec3f_Copy(EffectParams *params);
extern void EffectSs_Spawn(s32 arg0, s32 arg1, s32 arg2, EffectParams *params);

// Remaining diff: the ROM does not spill a1 and reads the four floats from the a2 slot on (an 8-aligned 16-byte argument?).
void EffectSsBubble_Spawn(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    EffectParams params;

    Math_Vec3f_Copy(&params);
    params.unkC = arg2;
    params.unk10 = arg3;
    params.unk14 = arg4;
    params.unk18 = arg5;
    EffectSs_Spawn(arg0, 7, 0x80, &params);
}
