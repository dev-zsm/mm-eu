// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0233.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80971810();                            /* extern */
extern M2C_UNK D_8097191C;

void EnSi_Wait(EnSi *this) {
    if ((M2C_FIELD(this, s32 *, 4) & 0x2000) == 0x2000) {
        M2C_FIELD(this, M2C_UNK **, 0x144) = &D_8097191C;
        goto block_4;
    }
    if (M2C_FIELD(this, u8 *, 0x15B) & 1) {
        func_80971810();
        func_800B6490(this);
        return;
    }
block_4:
    M2C_FIELD(this, s16 *, 0xBE) = (s16) (M2C_FIELD(this, s16 *, 0xBE) + 0x38E);
}
