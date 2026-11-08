#include "types.h"

typedef struct {
    u8 pad0[0x1E];
    s8 unk1E;
    u8 pad1F[0x9D];
    f32 unkBC[3];
    u8 padC8[0xC8];
    s8 unk190;
    s8 unk191;
    s8 unk192;
    s8 unk193;
} Fn800F0834Act;

extern s32 D_801EFA18;
extern void ActorShape_Init(f32 *, f32, s32, f32);
extern void EnHy_ChangeObjectAndAnim(Fn800F0834Act *, u8 *, s16);
extern void SkelAnime_InitFlex(u8 *, u8 *, s32, s32, u8 *, u8 *, s32);
extern s32 SubS_IsObjectLoaded(s8, u8 *);

s32 EnHy_Init(Fn800F0834Act *arg0, u8 *arg1, s32 arg2, s16 arg3) {
    s32 sp34;

    sp34 = 0;
    if (SubS_IsObjectLoaded(arg0->unk193, arg1) == 1 && SubS_IsObjectLoaded(arg0->unk190, arg1) == 1 &&
        SubS_IsObjectLoaded(arg0->unk191, arg1) == 1 && SubS_IsObjectLoaded(arg0->unk192, arg1) == 1) {
        arg0->unk1E = arg0->unk192;
        sp34 = 1;
        ActorShape_Init(arg0->unkBC, 0.0f, 0, 0.0f);
        D_801EFA18 = *(s32 *)((s32)arg1 + arg0->unk1E * 0x44 + 0x17D98) + 0x80000000;
        SkelAnime_InitFlex(arg1, (u8 *)arg0 + 0x14C, arg2, 0, (u8 *)arg0 + 0x206, (u8 *)arg0 + 0x266, 0x10);
        EnHy_ChangeObjectAndAnim(arg0, arg1, arg3);
    }
    return sp34;
}
