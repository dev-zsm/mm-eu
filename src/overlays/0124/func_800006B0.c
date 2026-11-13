#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808E379C(u8 *);                      /* extern */
extern M2C_UNK D_808E3D24;

void func_800006B0(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    s16 temp_v0;

    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0x7D0, 0);
    if ((M2C_FIELD(arg0, f32 *, 0x98) > 240.0f) || (M2C_FIELD(arg0, f32 *, 0x98) <= 40.0f)) {
        M2C_FIELD(arg0, s16 *, 0x24C) = 0;
        func_808E379C(arg0);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x24C);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x24C) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x24E) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0x24C) = 0;
    M2C_FIELD(arg0, s16 *, 0x24A) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1F4) = &D_808E3D24;
}
