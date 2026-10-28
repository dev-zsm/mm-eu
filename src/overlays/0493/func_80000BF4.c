// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B695C(u8 *);                      /* extern */
s16 func_800B6A58(u8 *, u8 *);                  /* extern */
M2C_UNK func_800BE0C0(u8 *, s32, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80000BF4(u8 *arg0, M2C_UNK arg1) {
    func_800BE0C0(arg0 + 0x24, M2C_FIELD(arg0, u8 **, 0x360) + 0x24, arg0 + 0x30, 0);
    func_800FFCBC(arg0 + 0xBE, func_800B6A58(arg0, M2C_FIELD(arg0, u8 **, 0x360)), 3, 0xE38, 0x38E);
    M2C_FIELD(arg0, f32 *, 0x70) = 3.5f;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x360), f32 *, 0x28);
    func_800B695C(arg0);
}
