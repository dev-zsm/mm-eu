// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 flags;
    /* 0x008 */ u8 pad8[0x2A];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x40];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 pad78[0x46];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x124];
    /* 0x1E4 */ s32 unk1E4;
    /* 0x1E8 */ s16 unk1E8;
} Ent;
s32 EnHy_FindNearestDoor(Ent *, s32);
void func_800F0954(Ent *, s32, s32, s16, s32);
s16 Math_Vec3f_Yaw(u8 *, s32, s32);
s32 SubS_CopyPointFromPath(s32, s16, u8 *);
s32 func_800F0B74(Ent *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 ret; u8 *p; s32 q;
    ret = 0;
    arg0->unk1E8 = 0;
    p = (u8 *)arg0 + 0x24;
    if (SubS_CopyPointFromPath(arg0->unk1E4, arg0->unk1E8, p) != 0) {
        q = EnHy_FindNearestDoor(arg0, arg1);
        if (q != 0) {
            ret = 1;
            func_800F0954(arg0, arg1, q, arg2, arg3);
            arg0->unkBE = Math_Vec3f_Yaw(p, q + 0x24, q);
            arg0->unk32 = arg0->unkBE;
            arg0->flags &= ~1;
            arg0->unk74 = 0.0f;
        }
    }
    return ret;
}
