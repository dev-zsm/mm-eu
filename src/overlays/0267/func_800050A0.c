// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A9868(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_8099BF1C;

void func_800050A0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099BF1C;
    M2C_FIELD(arg0, s32 *, 0x684) = 0;
    M2C_FIELD(arg0, s16 *, 0x688) = 0;
    M2C_FIELD(arg0, f32 *, 0x6A4) = 0.0f;
    func_801A9868(0x101400FF, arg0);
}
