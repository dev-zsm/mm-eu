// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0580.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BBCDE0;

void BgIknvObj_UpdateSakonDoor(BgIknvObj *this, PlayState *play) {
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF32) & 0x80) {
        M2C_FIELD(this, M2C_UNK **, 0x1AC) = &D_80BBCDE0;
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) | 0x80);
    }
    func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)this + 0x15C, this);
}
