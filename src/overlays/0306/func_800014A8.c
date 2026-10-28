// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A0CB08(u8 *, s32);                 /* extern */
M2C_UNK func_80A0D758();                            /* extern */
extern f32 D_80A0E4E8;

void func_800014A8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x2A8) = (f32) (M2C_FIELD(arg0, f32 *, 0x2A8) - D_80A0E4E8);
    if (M2C_FIELD(arg0, f32 *, 0x2A8) < 0.5f) {
        func_80A0D758();
    }
    func_80A0CB08(arg0, arg1);
}
