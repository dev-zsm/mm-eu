// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0138.h"

s32 func_8012FA08(s32, u8, u8 *, s32);            /* extern */

void ItemEtcetera_WaitForObject(ItemEtcetera *this, PlayState *play) {
    if (func_8012FA08((u8 *)play + 0x17D88, M2C_FIELD(this, u8 *, 0x14C), this, play) != 0) {
        M2C_FIELD(this, u8 *, 0x1E) = (u8) M2C_FIELD(this, u8 *, 0x14C);
        M2C_FIELD(this, s32 *, 0x13C) = (s32) M2C_FIELD(this, s32 *, 0x150);
        M2C_FIELD(this, s32 *, 0x154) = (s32) M2C_FIELD(this, s32 *, 0x144);
    }
}
