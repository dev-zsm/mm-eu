#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s16, u8 *);                 /* extern */

void func_80000834(u8 *arg0) {
    s16 temp_v1;
    u32 var_v0;

    var_v0 = M2C_FIELD(arg0, u16 *, 0x30A);
    if (!(var_v0 & 4)) {
        temp_v1 = M2C_FIELD(arg0, s16 *, 0x31A);
        if (temp_v1 != -1) {
            func_800F1D6C(M2C_FIELD(((u8 *)((s32)arg0 + (temp_v1 * 2))), s16 *, 0x30C), arg0);
            var_v0 = M2C_FIELD(arg0, u16 *, 0x30A);
        }
    }
    M2C_FIELD(arg0, s16 *, 0x31A) = -1;
    M2C_FIELD(arg0, u16 *, 0x30A) = (u16) (var_v0 & 0xFFFB);
}
