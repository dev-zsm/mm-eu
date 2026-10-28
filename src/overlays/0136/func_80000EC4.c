// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80900C14();                            /* extern */
extern M2C_UNK D_80901AA4;

void func_80000EC4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x24C) = 9;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, f32 *, 0x1C0) = 1.0f;
    func_80900C14();
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_80901AA4;
}
