// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8091F978(u8 *);                      /* extern */
M2C_UNK func_8091F9B4(u8 *);                      /* extern */
M2C_UNK func_809204B0(u8 *);                      /* extern */
extern f32 D_8092197C;

void func_80000D70(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (M2C_FIELD(arg0, f32 *, 0x5C) - D_8092197C);
    if (M2C_FIELD(arg0, f32 *, 0x5C) <= M2C_FIELD(arg0, f32 *, 0x254)) {
        func_8091F9B4(arg0);
        func_8013F090(M2C_FIELD(arg0, f32 *, 0x94), 0x78, 0x14, 0xA);
        func_8091F978(arg0);
        func_809204B0(arg0);
    }
}
