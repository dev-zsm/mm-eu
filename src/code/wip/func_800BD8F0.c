#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 flags;
    /* 0x08 */ u8 pad8[0x1C];
    /* 0x24 */ u8 pos[1];
} Act;

typedef struct {
    /* 0x0000 */ u8 pad0[0xE0];
    /* 0x00E0 */ u8 unkE0[1];
    /* 0x00E1 */ u8 padE1[0x1C4B];
    /* 0x1F2C */ u8 unk1F2C;
    /* 0x1F2D */ u8 pad1F2D[0xFFFF - 0x1F2D];
} Gfx;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1CCC];
    /* 0x1CCC */ Act *player;
    /* 0x1CD0 */ u8 pad1CD0[0x25C];
    /* 0x1F2C */ u8 unk1F2C;
} Play;

extern f32 Math_Vec3f_DistXYZ();
extern void Math_SmoothStepToS();
extern s32 D_801C9630;

s16 func_800BD8F0(Act *a, Play *g, s16 arg2, f32 arg3) {
    Act *p = g->player;

    if (arg3 < ((g->unk1F2C != 0 || D_801C9630 != 0) ? Math_Vec3f_DistXYZ(a->pos, (u8 *)g + 0xE0, g) * 0.25f : Math_Vec3f_DistXYZ(a->pos, p->pos, g))) {
        a->flags &= ~1;
        Math_SmoothStepToS(&arg2, 0, 6, 0x14, 1);
    } else {
        a->flags |= 1;
        Math_SmoothStepToS(&arg2, 0xFF, 6, 0x14, 1);
    }
    return arg2;
}
