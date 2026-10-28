// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7D4C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_8018132C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */

void func_80000BA0(u8 *arg0, s32 arg1) {
    func_8018132C(M2C_FIELD(arg0, f32 *, 8), M2C_FIELD(arg0, f32 *, 0xC) + ((f32) arg1 * 12.0f) + 10.0f, M2C_FIELD(arg0, s32 *, 0x10), 0);
    func_8018142C(M2C_FIELD(arg0, f32 *, 0x58), M2C_FIELD(arg0, f32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60), 1);
    func_800E7D4C(0, arg0 + 0x144);
}
