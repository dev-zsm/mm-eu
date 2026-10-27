// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800B6BF0;

typedef struct {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ Vec3f_800B6BF0 pos;
    /* 0x30 */ u8 pad30[0xBE - 0x30];
    /* 0xBE */ s16 unkBE;
} Actor_800B6BF0;

extern f32 Math_CosS(s16);
extern f32 Math_SinS(s16);

void Actor_WorldToActorCoords(Actor_800B6BF0 *arg0, Vec3f_800B6BF0 *arg1, Vec3f_800B6BF0 *arg2) {
    f32 sp1C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;

    sp1C = Math_CosS(arg0->unkBE);
    temp_f0 = Math_SinS(arg0->unkBE);
    temp_f2 = arg2->x - arg0->pos.x;
    temp_f12 = arg2->z - arg0->pos.z;
    arg1->x = (temp_f2 * sp1C) - (temp_f12 * temp_f0);
    arg1->z = (temp_f12 * sp1C) + (temp_f2 * temp_f0);
    arg1->y = arg2->y - arg0->pos.y;
}
