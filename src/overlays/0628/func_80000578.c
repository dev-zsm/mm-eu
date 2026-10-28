// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BEE368;

void func_80000578(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800B877C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80BEE368;
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) | 0x80);
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) & 0x80) {
        func_800B87A0(arg0, arg1, 4, 0x44FA0000, 1000.0f);
        return;
    }
    func_800B87A0(arg0, arg1, 0xC, 0x44FA0000, 1000.0f);
}
