#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0232.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(u8 *, s32);                 /* extern */
M2C_UNK func_800E10CC(u8 *, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136ED0(u8 *, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
s32 func_8013D9F8(u8 *, s16, M2C_UNK);            /* extern */
M2C_UNK func_8096E81C(u8 *, u8 *);              /* extern */
M2C_UNK func_8096E938(u8 *);                      /* extern */
extern M2C_UNK D_60080F0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80971044;
extern M2C_UNK D_80971070;
extern M2C_UNK D_8097107C;
extern M2C_UNK D_8097119C;

void func_80002B68(Actor *thisx, PlayState *play) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14((u8 *)thisx + 0xBC, 0, &D_800B3F30, 0x41C00000);
    func_80136ED0(play, (u8 *)thisx + 0x14C, &D_60080F0, 0, (u8 *)thisx + 0x1E4, (u8 *)thisx + 0x232, 0xD);
    temp_a1 = (u8 *)thisx + 0x190;
    sp34 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_80971044);
    func_800E731C((u8 *)thisx + 0xA0, &D_8097107C, &D_80971070);
    func_800FF8DC(thisx, &D_8097119C);
    M2C_FIELD(thisx, s32 *, 0x1DC) = func_8013D9F8(play, (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0xFC00) >> 0xA), 0x3F);
    func_800B6564(thisx, 0x3BF5C28F);
    M2C_FIELD(thisx, s8 *, 0x1F) = 1;
    M2C_FIELD(thisx, f32 *, 0x74) = -3.0f;
    M2C_FIELD(thisx, s16 *, 0x282) = func_800FF250(0x3C, 0x3C);
    M2C_FIELD(thisx, s16 *, 0x280) = 0;
    M2C_FIELD(thisx, s16 *, 0x28E) = 0x14;
    M2C_FIELD(thisx, s16 *, 0x284) = 0xA;
    M2C_FIELD(thisx, s16 *, 0x286) = (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x3E0) >> 5);
    M2C_FIELD(thisx, s16 *, 0x28C) = 0;
    M2C_FIELD(thisx, s16 *, 0x290) = 0;
    if (M2C_FIELD(play, s16 *, 0xA4) == 0x41) {
        M2C_FIELD(thisx, s16 *, 0x28A) = 0x64;
        func_8096E938(thisx);
    }
    func_8096E81C(thisx, play);
}
