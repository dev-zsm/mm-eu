// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s16);                        /* extern */
M2C_UNK func_80BCB1A8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80BCB484;

void func_800003E4(u8 *arg0, s32 arg1) {
    s16 temp_a1;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(&D_801E6EF0, s32 *, 0x18) - 1;
    switch (temp_v0) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, s16 *, 0x28A) = 0;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF38) & 2) {
            M2C_FIELD(arg0, s16 *, 0x28A) = 6;
        }
        func_80BCB1A8(arg0, 8);
        break;
    case 1:
        M2C_FIELD(arg0, s16 *, 0x28A) = 2;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF38) & 4) {
            M2C_FIELD(arg0, s16 *, 0x28A) = 7;
        }
        func_80BCB1A8(arg0, 8);
        break;
    case 2:
        M2C_FIELD(arg0, s16 *, 0x28A) = 4;
        M2C_FIELD(arg0, f32 *, 0x264) = 1.0f;
        func_80BCB1A8(arg0, 0xA);
        break;
    }
    temp_a1 = M2C_FIELD(arg0, s16 *, 0x278);
    M2C_FIELD(arg0, f32 *, 0x264) = 1.0f;
    if ((temp_a1 >= 0) && (func_800B5B20(arg1, temp_a1) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x28A) = 5;
        if (M2C_FIELD(arg0, s16 *, 0x276) != 0xA) {
            func_80BCB1A8(arg0, 0xA);
        }
    }
    M2C_FIELD(arg0, s16 *, 0x288) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80BCB484;
}
