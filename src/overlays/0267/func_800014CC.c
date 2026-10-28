// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6022728;
extern M2C_UNK D_80998358;

void func_800014CC(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    func_80137828(arg0 + 0x194, &D_6022728, 0xC0A00000);
    temp_f6 = (f32) func_80134AE8(&D_6022728);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80998358;
    M2C_FIELD(arg0, f32 *, 0x1D8) = temp_f6;
}
