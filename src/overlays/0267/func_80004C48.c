// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60079D4;
extern M2C_UNK D_8099BAD4;

void func_80004C48(u8 *arg0, M2C_UNK arg1) {
    func_80137828(arg0 + 0x194, &D_60079D4, 0xC1200000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099BAD4;
    M2C_FIELD(arg0, s8 *, 0x148) = 0;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x3C;
    M2C_FIELD(arg0, f32 *, 0x1B0) = 0.0f;
}
