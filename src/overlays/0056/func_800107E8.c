// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1C8(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DDF8;
extern M2C_UNK D_8084E544;

void func_800107E8(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084E544, 0);
    func_8082D1C8(arg1, arg0, &D_400DDF8);
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x10);
}
