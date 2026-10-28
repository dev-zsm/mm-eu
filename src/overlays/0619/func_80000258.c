// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80BEB5FC(u8 *);                      /* extern */
extern u8 D_801E7E32;
extern M2C_UNK D_80BEB6B0;

void func_80000258(u8 *arg0, s32 arg1) {
    if ((D_801E7E32 & 0x80) && (M2C_FIELD(arg0, M2C_UNK **, 0x13C) == NULL)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80BEB6B0;
        func_800BA9E4(arg1 + 0x1CA0, arg1, 1, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, -1);
    }
    if (M2C_FIELD(arg0, M2C_UNK **, 0x13C) != NULL) {
        if (func_800B877C(arg0, arg1) != 0) {
            M2C_FIELD(arg0, s32 *, 0x120) = 0;
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
            func_80BEB5FC(arg0);
            return;
        }
        if (M2C_FIELD(arg0, f32 *, 0x98) < 25.0f) {
            func_800B87A0(arg0, arg1, 0x96, 0x42C80000, 30.0f);
        }
    }
}
