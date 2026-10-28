// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B2030(u8 *, u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800BA9E4(u8 *, u8 *, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_809F83E8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_801C9EE0;

void func_80002758(u8 *arg0, u8 *arg1) {
    func_809F83E8(arg1, 0x6C77, 7, 0x14);
    M2C_FIELD(arg1, s8 *, 0x1CA2) = 4;
    func_800BA9E4(arg1 + 0x1CA0, arg1, 1, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 0);
    func_800B2030(arg1, arg0 + 0x24, &D_801C9EE0, &D_801C9EE0);
}
