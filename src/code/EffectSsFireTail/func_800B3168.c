#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ f32 pos[3];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 vel[3];
    /* 0x20 */ s16 unk20;
    /* 0x22 */ u8 c1[4];
    /* 0x26 */ u8 c2[4];
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 pad2E;
    /* 0x30 */ s32 unk30;
} FireTail;

extern void Math_Vec3f_Copy(f32 *, f32 *);
extern void Color_RGBA8_Copy(u8 *, u8 *);
extern void EffectSs_Spawn(s32, s32, s32, FireTail *);

void EffectSsFireTail_Spawn(s32 a0, s32 a1, f32 *a2, f32 a3, f32 *a4, s16 a5, u8 *a6, u8 *a7, s16 a8, s16 a9, s32 a10) {
    FireTail init;

    Math_Vec3f_Copy(init.pos, a2);
    Math_Vec3f_Copy(init.vel, a4);
    Color_RGBA8_Copy(init.c1, a6);
    Color_RGBA8_Copy(init.c2, a7);
    init.unk20 = a5;
    init.unk0 = a1;
    init.unk10 = a3;
    init.unk2A = a8;
    init.unk2C = a9;
    init.unk30 = a10;
    EffectSs_Spawn(a0, 0x1C, 0x80, &init);
}
