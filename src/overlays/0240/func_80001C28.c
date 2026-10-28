// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_8097ACD8(u8 *);                      /* extern */
M2C_UNK func_8097AF24(u8 *);                      /* extern */
extern M2C_UNK D_8097C070;

void func_80001C28(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x3D2) == 0) {
        M2C_FIELD(arg0, s16 *, 0x3D2) = 0;
        M2C_FIELD(arg0, f32 *, 0x230) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x22C) = 0.0f;
        if (M2C_FIELD(arg0, u8 *, 0xB7) != 0) {
            func_800BC8F4(arg0, 0x4000, 0xFF, 0, 8);
            func_800BD9E0(arg0 + 0x144, &D_8097C070, 3);
            M2C_FIELD(arg0, s16 *, 0x3D8) = (s16) (M2C_FIELD(arg0, s16 *, 0x3D8) | 1);
            func_8097ACD8(arg0);
            return;
        }
        func_8097AF24(arg0);
    }
}
