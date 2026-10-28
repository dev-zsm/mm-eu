// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */

void func_80002774(u8 *arg0) {
    u8 *temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x203) == 0) {
        M2C_FIELD(arg0, f32 *, 0x204) = 1.0f;
    }
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x1A0);
    if ((temp_v0 != NULL) && (M2C_FIELD(arg0, f32 *, 0x204) != M2C_FIELD(temp_v0, f32 *, 0x15C))) {
        M2C_FIELD(temp_v0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x1A0), f32 *, 0x158) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x1A0), f32 *, 0x15C) = (f32) M2C_FIELD(arg0, f32 *, 0x204);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x1D8)();
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF) < 2) {
        func_800B6564(arg0, (f32) M2C_FIELD(arg0, s16 *, 0x1C4) / 100.0f);
    }
}
