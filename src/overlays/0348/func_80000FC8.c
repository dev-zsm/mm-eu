// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B13D0(s32, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_80A3D1F8;
extern M2C_UNK D_80A3D204;

void func_80000FC8(s32 arg0, s32 arg1) {
    func_800B13D0(arg1, arg0 + 0x230, &D_801C9EE0, &D_80A3D1F8, &D_80A3D204, &D_80A3D204, 0x4B, 7, 8);
}
