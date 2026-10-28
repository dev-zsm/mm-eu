// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_801812D4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A9E704(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9E3D0;
extern M2C_UNK D_80A9E438;
extern M2C_UNK D_80A9E46C;
extern M2C_UNK D_80A9E4E4;

void func_80004F3C(u8 *arg0, s32 arg1) {
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x2A4), M2C_FIELD(arg0, s32 *, 0x2C0), M2C_FIELD(arg0, u8 *, 0x2A2), &D_80A9E438, &D_80A9E4E4, arg0);
    func_80A9E704(arg0, arg1);
    func_801812D4(arg0 + 0x36C, 0);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x14C), M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, u8 *, 0x14A), &D_80A9E3D0, &D_80A9E46C, arg0);
}
