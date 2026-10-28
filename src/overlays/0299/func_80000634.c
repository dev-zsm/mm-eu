// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801826E0(f32, f32, s32, u8 *);       /* extern */
M2C_UNK func_80182B28(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_80A02138;

void func_80000634(u8 *arg0, s32 arg1) {
    func_801826E0(M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, s32 *, 0x2C), arg0 + 0xBC);
    func_80182B28(&D_80A02138, arg1);
}
