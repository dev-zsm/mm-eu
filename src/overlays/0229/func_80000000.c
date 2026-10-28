// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_8096AA7C(u8 *);                      /* extern */
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_8096AF30;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0x43C80000, &D_800B3F30, 0x41500000);
    func_800E1134(arg1, arg0 + 0x148, arg0, &D_8096AF30);
    M2C_FIELD(arg0, s16 *, 0xBE) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 2) {
        M2C_FIELD(arg0, s16 *, 0x144) = 1;
        M2C_FIELD(arg0, s16 *, 0x146) = 0;
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    } else {
        M2C_FIELD(arg0, s16 *, 0x144) = 0x14;
        M2C_FIELD(arg0, s16 *, 0x146) = 0x13;
        M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
    }
    M2C_FIELD(arg0, s16 *, 0x30) = (s16) -M2C_FIELD(arg0, s16 *, 0xBC);
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        func_8096AA7C(arg0);
    }
}
