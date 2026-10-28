// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136AAC(s32, u8 *);                 /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80849CB4;

void func_8000D464(u8 *arg0, s16 arg1, s32 arg2) {
    func_80830B44(arg2, arg0, &D_80849CB4, 1);
    func_80136AAC(arg2, arg0 + 0x240);
    M2C_FIELD(arg0, f32 *, 0xB38) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xB34) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0xAD4) = arg1;
}
