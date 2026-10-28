// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7D4C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_801826E0(f32, f32, s32, u8 *);       /* extern */

void func_80000068(u8 *arg0) {
    func_801826E0(M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), arg0 + 0xBC);
    func_8018142C(M2C_FIELD(arg0, f32 *, 0x58), M2C_FIELD(arg0, f32 *, 0x5C), M2C_FIELD(arg0, s32 *, 0x60), 1);
    func_800E7D4C(0, arg0 + 0x2A8);
}
