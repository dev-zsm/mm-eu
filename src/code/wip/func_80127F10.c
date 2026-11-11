#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x2B0];
    /* 0x2B0 */ u32 *p;
    /* 0x2B4 */ s32 unk2B4;
} Gfx_;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s_;

extern f32 D_801D5E20;
extern f32 D_801D5E24;
extern Vec3s_ D_801ED258;

void Matrix_Push(void *, s32);
void Matrix_Pop(void);
void Matrix_SetTranslateRotateYXZ(f32, f32, f32, s16 *);
void Matrix_ToMtx(s32);

void Player_DrawBunnyHood(Gfx_ **arg0) {
    s16 sp2C[3];
    s32 sp34;
    s32 temp;
    u32 *p;

    temp = (*arg0)->unk2B4 - 0x80;
    (*arg0)->unk2B4 = temp;
    p = (*arg0)->p;
    (*arg0)->p = p + 2;
    p[1] = temp;
    p[0] = 0xDB06002C;
    Matrix_Push(arg0, temp);
    sp2C[0] = D_801ED258.y + 0x3E2;
    sp2C[1] = D_801ED258.z + 0xDBE;
    sp2C[2] = D_801ED258.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f, D_801D5E20, -240.0f, sp2C);
    sp34 = temp + 0x40;
    Matrix_ToMtx(temp);
    sp2C[0] = D_801ED258.y - 0x3E2;
    sp2C[1] = -0xDBE - D_801ED258.z;
    sp2C[2] = D_801ED258.x - 0x348A;
    Matrix_SetTranslateRotateYXZ(97.0f, D_801D5E24, 240.0f, sp2C);
    Matrix_ToMtx(sp34);
    Matrix_Pop();
}
