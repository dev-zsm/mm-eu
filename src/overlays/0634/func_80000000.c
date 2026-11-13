#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0634.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80BF87CC(u8 *, s32);                 /* extern */
M2C_UNK func_80BF8914(u8 *);                      /* extern */
extern M2C_UNK D_6008AB8;
extern M2C_UNK D_60092FC;
extern M2C_UNK D_800B3F30;
extern s32 D_801E6EF0;
extern M2C_UNK D_80BF9E18;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x42100000);
    func_80136ED0(play, (u8 *)thisx + 0x190, &D_6008AB8, &D_60092FC, (u8 *)thisx + 0x220, (u8 *)thisx + 0x286, 0x11);
    temp_a1 = (u8 *)thisx + 0x144;
    sp34 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80BF9E18);
    M2C_FIELD(thisx, s8 *, 0x1F) = 6;
    M2C_FIELD(thisx, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    if (D_801E6EF0 == 0x68D0) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x10000);
    }
    M2C_FIELD(thisx, s16 *, 0x2F8) = 0;
    M2C_FIELD(thisx, s16 *, 0x2FA) = 0;
    M2C_FIELD(thisx, s32 *, 0x21C) = 0;
    M2C_FIELD(thisx, s16 *, 0x2FE) = 0;
    func_80BF87CC(thisx, play);
    func_80BF8914(thisx);
}
