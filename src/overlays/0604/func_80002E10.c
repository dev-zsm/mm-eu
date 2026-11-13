#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0604.h"

M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK func_8013C01C(u8 *, M2C_UNK *, s16);      /* extern */
extern M2C_UNK D_80BD4890;
extern M2C_UNK D_80BD50BC;
extern f32 D_80BD5520;

void func_80002E10(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x34C);
    M2C_FIELD(arg0, s16 *, 0x352) = (s16) (M2C_FIELD(arg0, s16 *, 0x362) + M2C_FIELD(arg0, s16 *, 0x352));
    if (temp_f0 >= 1.0f) {
        M2C_FIELD(arg0, f32 *, 0x34C) = 1.0f;
        M2C_FIELD(arg0, f32 *, 0x68) = 5.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x68) = 5.0f;
        M2C_FIELD(arg0, f32 *, 0x34C) = (f32) (temp_f0 + D_80BD5520);
    }
    if ((M2C_FIELD(arg0, f32 *, 0xC) + 200.0f) < M2C_FIELD(arg0, f32 *, 0x28)) {
        func_800FFBF8(arg0 + 0x68, 0.0f, 0x3E4CCCCD, 1.0f);
        M2C_FIELD(arg0, s16 *, 0x338) = 0xA;
        func_8013C01C(arg0 + 0x144, &D_80BD50BC, M2C_FIELD(arg0, s16 *, 0x338));
        if ((M2C_FIELD(arg0, s16 *, 0x1C) & 3) == 2) {
            M2C_FIELD(arg0, u16 *, 0x32C) = (u16) (M2C_FIELD(arg0, u16 *, 0x32C) | 2);
        }
        M2C_FIELD(arg0, s16 *, 0x356) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80BD4890;
    }
}
