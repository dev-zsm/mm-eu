// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80902218();                            /* extern */
extern f32 D_809045FC;

void func_800002D4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x242) = 0x190;
    M2C_FIELD(arg0, f32 *, 0x25C) = (f32) (M2C_FIELD(arg0, f32 *, 0x260) * D_809045FC);
    func_80902218();
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
}
