// FLAGS: -O2 -g3 -mips2
// STATUS: ours spills the unused second argument (sw a1), the ROM does not
#include "types.h"

typedef struct {
    f32 x, y, z;
    s16 a;
    s16 b;
    s16 c;
} RippleParams;

extern void Math_Vec3f_Copy(RippleParams *params);
extern void EffectSs_Spawn(void *play, s32 type, s32 priority, RippleParams *params);

void EffectSsGRipple_Spawn(void *play, void *unused, s16 a, s16 b, s16 c) {
    RippleParams params;

    Math_Vec3f_Copy(&params);
    params.a = a;
    params.b = b;
    params.c = c;
    EffectSs_Spawn(play, 9, 0x80, &params);
}
