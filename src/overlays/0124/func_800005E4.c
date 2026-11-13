#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0124.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_808E379C(u8 *);                      /* extern */
M2C_UNK func_808E3890(u8 *);                      /* extern */
extern M2C_UNK D_6000194;

void func_800005E4(u8 *arg0, M2C_UNK arg1) {
    f32 sp2C;
    f32 temp_f0;

    sp2C = M2C_FIELD(arg0, f32 *, 0x15C);
    if ((f32) func_80134AE8(&D_6000194) <= sp2C) {
        M2C_FIELD(arg0, s16 *, 0x24C) = 0x14;
        func_808E3890(arg0);
        return;
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0x7D0, 0);
    if ((M2C_FIELD(arg0, f32 *, 0x98) > 240.0f) || (M2C_FIELD(arg0, f32 *, 0x98) <= 40.0f)) {
        M2C_FIELD(arg0, s16 *, 0x24C) = 0;
        func_808E379C(arg0);
    }
}
