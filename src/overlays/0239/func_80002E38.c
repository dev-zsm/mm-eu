// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6005700;
extern M2C_UNK D_80977ED4;

void func_80002E38(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6005700, 0xC0800000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80977ED4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
