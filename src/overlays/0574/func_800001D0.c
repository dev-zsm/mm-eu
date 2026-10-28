// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDDC0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80131AF8(s32, s32, u8 *);            /* extern */
extern M2C_UNK D_6001100;

void func_800001D0(u8 *arg0, s32 arg1) {
    func_80131AF8(arg1, M2C_FIELD(arg0, s32 *, 0x190), arg0);
    func_800BDDC0(arg1, &D_6001100);
}
