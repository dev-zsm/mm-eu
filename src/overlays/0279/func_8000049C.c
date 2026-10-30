// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E0F5C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800E10CC(M2C_UNK, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
s32 func_8013D9F8(M2C_UNK, s16, M2C_UNK);           /* extern */
s8 func_8013DCD4(M2C_UNK, M2C_UNK);                 /* extern */
extern M2C_UNK D_809B0250;
extern M2C_UNK D_809B0C30;
extern M2C_UNK D_809B0C5C;
extern M2C_UNK D_809B0C68;

void func_8000049C(Actor *thisx, PlayState *play) {
    u8 *sp24;
    u8 *temp_a1;

    M2C_FIELD(thisx, s8 *, 0x193) = func_8013DCD4(0x9D, play);
    M2C_FIELD(thisx, s8 *, 0x190) = func_8013DCD4(0xDA, play);
    M2C_FIELD(thisx, s8 *, 0x191) = func_8013DCD4(0xDA, play);
    M2C_FIELD(thisx, s8 *, 0x192) = func_8013DCD4(0xDA, play);
    if ((M2C_FIELD(thisx, s8 *, 0x193) < 0) || (M2C_FIELD(thisx, s8 *, 0x190) < 0) || (M2C_FIELD(thisx, s8 *, 0x191) < 0) || (M2C_FIELD(thisx, s8 *, 0x192) < 0)) {
        func_800B6490(thisx);
    }
    M2C_FIELD(thisx, s32 *, 0x13C) = 0;
    temp_a1 = (u8 *)thisx + 0x194;
    sp24 = temp_a1;
    func_800E0F5C(play, temp_a1);
    func_800E10CC(play, temp_a1, thisx, &D_809B0C30);
    func_800E731C((u8 *)thisx + 0xA0, &D_809B0C68, &D_809B0C5C);
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    M2C_FIELD(thisx, s32 *, 0x1E4) = func_8013D9F8(play, (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x7E00) >> 9), 0x3F);
    M2C_FIELD(thisx, s8 *, 0x1E2) = 1;
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_809B0250;
}
