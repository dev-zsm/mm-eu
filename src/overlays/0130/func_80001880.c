// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808F98F8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_808FA654;

void func_80001880(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1E6) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808FA654;
        return;
    }
    func_800FFCBC(arg0 + 0xBE, (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000), 0xA, 0x3E8, 0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (M2C_FIELD(arg0, f32 *, 0x70) == 0.0f) {
        func_808F98F8(arg0, 0x40000000);
    }
}
