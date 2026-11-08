#include "types.h"

typedef struct {
    s8 unk0;
    s8 unk1;
    u8 pad2[2];
    u8 *unk4;
} Fn80122C10Path;

typedef struct {
    u8 pad0[0x24];
    f32 x;
    f32 y;
} Fn80122C10Player;

typedef struct {
    u8 pad0[0x1CCC];
    Fn80122C10Player *unk1CCC;
    u8 pad1CD0[0x238];
    u8 unk1F08;
} Fn80122C10Play;

f32 fabsf(f32);
#pragma intrinsic (fabsf)

extern void func_800B6CA4(Fn80122C10Play *, void *, f32, s16);
extern void Math_Vec3s_ToVec3f(f32 *, void *);
extern f32 Math_Vec3f_DistXZ(void *, f32 *);
extern s16 Math_Vec3f_Yaw(void *, f32 *);

s32 Player_UpdateOverrideInput(Fn80122C10Play *arg0, Fn80122C10Path *arg1, f32 arg2) {
    Fn80122C10Player *sp3C;
    f32 sp30[3];
    void *sp20;
    f32 dist;

    if (arg1->unk1 < arg1->unk0) {
        sp3C = arg0->unk1CCC;
        Math_Vec3s_ToVec3f(sp30, arg1->unk4 + arg1->unk1 * 6);
        sp20 = &sp3C->x;
        func_800B6CA4(arg0, (u8 *)arg0 + 0x1F0C, arg2, Math_Vec3f_Yaw(sp20, sp30));
        arg0->unk1F08 = 1;
        dist = Math_Vec3f_DistXZ(sp20, sp30);
        if (fabsf(sp3C->y - sp30[1]) < 50.0f && dist < arg2) {
            arg1->unk1++;
        }
        return 0;
    }
    return 1;
}
