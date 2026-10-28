// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C();                            /* extern */
extern M2C_UNK D_80A98908;

void func_80000DB4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x28) < 0.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x174) = &D_80A98908;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x160) = (s16) (M2C_FIELD(arg0, s16 *, 0x160) + 0x64);
    func_800B680C();
}
