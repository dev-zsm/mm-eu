// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0120.h"

f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_808E0E94;
extern f32 D_808E1624;

void EnEncount2_Idle(EnEncount2 *this, PlayState *play) {
    M2C_FIELD(this, f32 *, 0x16C) = (f32) (M2C_FIELD(this, f32 *, 0x16C) + D_808E1624);
    M2C_FIELD(this, f32 *, 0x68) = func_800FEB84((s16) (s32) M2C_FIELD(this, f32 *, 0x16C));
    func_800FFBF8((u8 *)this + 0x168, 0x3DCCCCCD, 0x3E99999A, 0x3C23D70A);
    if ((M2C_FIELD(this, u8 *, 0x181) & 2) && (M2C_FIELD(this, u8 *, 0xB9) == 0xE)) {
        M2C_FIELD(this, s8 *, 0xB7) = 0;
        M2C_FIELD(this, s16 *, 0x162) = 1;
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_808E0E94;
    }
}
