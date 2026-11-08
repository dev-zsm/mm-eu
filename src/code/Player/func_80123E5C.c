#include "types.h"

typedef struct {
    u8 pad0[0x147];
    s8 unk147;
    u8 pad148[2];
    s8 unk14A;
    u8 unk14B;
    u8 pad14C[3];
    u8 unk14F;
    u8 pad150;
    u8 unk151;
    u8 unk152;
    u8 pad153[5];
    s32 unk158;
    u8 pad15C[4];
    s32 unk160;
    u8 pad164[0x908];
    s32 unkA6C;
} Fn80123E5C;

extern s32 D_801C0FB8[];
extern s32 D_801ED268;
extern s32 Player_IsHoldingTwoHandedWeapon(Fn80123E5C *);
extern s32 Player_IsGoronOrDeku(Fn80123E5C *);

void Player_SetModelsForHoldingShield(Fn80123E5C *arg0) {
    u8 v;

    if ((arg0->unkA6C & 0x400000) && (arg0->unk14A < 0 || arg0->unk14A == arg0->unk147) && Player_IsHoldingTwoHandedWeapon(arg0) == 0 &&
        Player_IsGoronOrDeku(arg0) == 0) {
        D_801ED268 = arg0->unk14B * 2;
        arg0->unk151 = 8;
        arg0->unk158 = D_801C0FB8[8] + D_801ED268 * 4;
        v = arg0->unk152;
        if (v == 0xE) {
            v = arg0->unk152 = 0xC;
        } else if (v == 0xF) {
            v = arg0->unk152 = 0xD;
        }
        arg0->unk160 = D_801C0FB8[v] + D_801ED268 * 4;
        arg0->unk14F = 2;
        arg0->unk14A = -1;
    }
}
