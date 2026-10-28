// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400();                                /* extern */
extern M2C_UNK D_80981AE0;

void func_80000890(u8 *arg0) {
    if (func_800B8400() != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
        M2C_FIELD(arg0, M2C_UNK **, 0x274) = &D_80981AE0;
    }
}
