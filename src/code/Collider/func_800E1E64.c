// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x2D];
    u8 unk2D;
    u8 pad2E[2];
    s32 unk30;
    s32 pad34;
    s32 unk38;
    u8 pad3C[0x34];
    u8 unk70[0xC];
    f32 unk7C;
} Col;
void Math_Vec3s_ToVec3f(void *, void *);
f32 Math3D_Vec3fDistSq(void *, s32);
void Collider_ResetACBase(s32, s32);
void Collider_ResetACElement(s32, s32);
s32 Collider_QuadSetNearestAC(s32 play, Col *col, s32 arg2) {
    u8 sp20[0x10]; // 0x10 only to match the stack layout
    f32 d;
    if (!(col->unk2D & 4)) {
        return 1;
    }
    Math_Vec3s_ToVec3f(sp20, col->unk70);
    d = Math3D_Vec3fDistSq(sp20, arg2);
    if (d < col->unk7C) {
        col->unk7C = d;
        if (col->unk30 != 0) {
            Collider_ResetACBase(play, col->unk30);
        }
        if (col->unk38 != 0) {
            Collider_ResetACElement(play, col->unk38);
        }
        return 1;
    }
    return 0;
}
