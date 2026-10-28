// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FFD8(M2C_UNK);                     /* extern */
extern M2C_UNK D_80BBC170;
extern f32 D_80BBC784;

void func_80000340(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0xC) + 68.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + D_80BBC784);
    if (temp_f0 < M2C_FIELD(arg0, f32 *, 0x28)) {
        M2C_FIELD(arg0, f32 *, 0x28) = temp_f0;
        M2C_FIELD(arg0, M2C_UNK **, 0x164) = &D_80BBC170;
    }
    func_8019FFD8(0x205E);
}
