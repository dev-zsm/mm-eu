// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808824E0();                            /* extern */

void func_8000765C(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3A0) = 0;
    M2C_FIELD(arg0, s32 *, 0x214) = 0;
    M2C_FIELD(arg0, s32 *, 0x200) = 0;
    M2C_FIELD(arg0, s32 *, 0x3A8) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_808824E0();
}
