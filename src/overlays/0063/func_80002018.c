#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
s32 func_8016A844(s32, s16);                        /* extern */
M2C_UNK func_8016A87C(s32, s16, u8 *, s32);       /* extern */
M2C_UNK func_8086B580(u8 *, s32);                 /* extern */

void func_80002018(u8 *arg0, s32 arg1) {
    s16 temp_a1;
    s16 temp_v1;

    func_80137070(arg0 + 0x144);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x2B6);
    M2C_FIELD(arg0, s8 *, 0x11C) = 0x10;
    if (temp_v1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) (temp_v1 - 1);
        if (M2C_FIELD(arg0, s16 *, 0x2B6) == 0) {
            M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
            M2C_FIELD(arg0, s8 *, 0xB6) = 0x32;
        }
    } else {
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x2BA);
        M2C_FIELD(arg0, s16 *, 0x2B8) = (s16) (M2C_FIELD(arg0, s16 *, 0x2B8) + 0xF00);
        if (temp_a1 != 0) {
            func_8016A87C(arg1, M2C_FIELD(arg0, s16 *, 0x2BA), arg0 + 0x24, func_8016A844(arg1, temp_a1) + 0x5C);
        }
        if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
            func_8086B580(arg0, arg1);
        }
    }
}
