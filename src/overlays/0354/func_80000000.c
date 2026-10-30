// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80A492B4(u8 *);                      /* extern */
extern M2C_UNK D_60043F0;
extern M2C_UNK D_600C240;

void func_80000000(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s8 *, 0x1F) = 1;
    M2C_FIELD(thisx, f32 *, 0xFC) = 400.0f;
    func_800B6564(thisx, 0x3C23D70A);
    M2C_FIELD(thisx, s16 *, 0xB0) = 0x64;
    M2C_FIELD(thisx, s16 *, 0x258) = 0;
    M2C_FIELD(thisx, s16 *, 0x25E) = 0;
    M2C_FIELD(thisx, s16 *, 0x260) = 0;
    M2C_FIELD(thisx, s16 *, 0x25C) = 0;
    M2C_FIELD(thisx, s16 *, 0x25A) = 0;
    func_80136ED0(play, (u8 *)thisx + 0x144, &D_600C240, &D_60043F0, (u8 *)thisx + 0x18C, (u8 *)thisx + 0x1EC, 0x10);
    func_80A492B4(thisx);
}
