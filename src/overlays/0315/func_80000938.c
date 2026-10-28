// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEA90(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80A192C0;

void func_80000938(s32 arg0, M2C_UNK arg1) {
    func_800FEA90(arg0 + 0x148, &D_80A192C0, 0xE0, arg0);
}
