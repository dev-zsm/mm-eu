// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600B0F8;
extern M2C_UNK D_809C8AC8;

void func_800015D4(u8 *arg0, M2C_UNK arg1, u8 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_809C8AC8;
    func_80137934(arg0 + 0x148, &D_600B0F8, 0xC1700000, arg0);
    M2C_FIELD(arg0, s16 *, 0x24C) = 0x64;
    M2C_FIELD(arg0, f32 *, 0x2C4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2B8) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x242) = arg2;
}
