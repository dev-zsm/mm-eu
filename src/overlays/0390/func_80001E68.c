// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
M2C_UNK func_80A9A9A4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9B6F8;

void func_80001E68(u8 *arg0, s32 arg1) {
    func_80147CC4(arg1);
    func_80A9A9A4(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x3C0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9B6F8;
    M2C_FIELD(arg0, s16 *, 0x360) = 0xF;
    func_800E7BB8(arg0, arg0 + 0x320);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 0;
    M2C_FIELD(arg0, u16 *, 0x3E4) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E4) & 0xFFF7);
}
