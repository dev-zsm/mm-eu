#include "types.h"

typedef struct {
    u8 pad0[0x80];
    s32 unk80;
    u8 pad84[1];
    u8 unk85;
    u8 pad86[6];
    f32 unk8C;
    u16 unk90;
    u8 pad92[0x15A];
    u8 unk1EC[0xC];
    u8 unk1F8[0xC];
    u8 unk204;
    u8 unk205;
} Fn800F0ECCAct;

extern void Actor_PlaySfx(Fn800F0ECCAct *, u16);
extern s32 SurfaceType_GetSfxOffset(u8 *, s32, u8);
extern s32 SubS_IsFloorAbove(u8 *, u8 *, s32);

s32 EnHy_PlayWalkingSound(Fn800F0ECCAct *arg0, u8 *arg1, s32 arg2) {
    u8 sp2F;
    u8 sp2E;
    s32 pad28; // matching: unused, pads the frame to the ROM size
    u16 sp26;
    s32 v;
    s32 t;

    sp2F = arg0->unk204;
    sp2E = arg0->unk205;
    if (arg0->unk90 & 0x20) {
        if (arg0->unk8C < 20.0f) {
            v = 4;
        } else {
            v = 5;
        }
        sp26 = v + 0x800;
    } else {
        sp26 = SurfaceType_GetSfxOffset(arg1 + 0x830, arg0->unk80, arg0->unk85) + 0x800;
    }
    t = SubS_IsFloorAbove(arg1, arg0->unk1EC, arg2);
    arg0->unk204 = t;
    if ((t & 0xFF) && sp2F == 0 && (u8)t) {
        Actor_PlaySfx(arg0, sp26);
    }
    t = SubS_IsFloorAbove(arg1, arg0->unk1F8, arg2);
    arg0->unk205 = t;
    if ((t & 0xFF) && sp2E == 0 && (u8)t) {
        Actor_PlaySfx(arg0, sp26);
    }
    return 0;
}
