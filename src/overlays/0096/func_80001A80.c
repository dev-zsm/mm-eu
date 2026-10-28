// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8010EE64(M2C_UNK);                     /* extern */
s32 func_8016A23C(u8 *);                          /* extern */
M2C_UNK func_808B7B70(u8 *, M2C_UNK *);           /* extern */
s32 func_808B7D4C(u8 *, u8 *);                  /* extern */
extern M2C_UNK D_808B96B0;

void func_80001A80(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    func_800B8C4C(arg0, 0x2025);
    if ((M2C_FIELD(arg0, u8 *, 0x203) == 0) && (func_808B7D4C(arg0, arg1) != 0) && (func_8016A23C(arg1) == 0) && (M2C_FIELD(arg0, u8 *, 0x203) == 0)) {
        sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
        func_8010EE64(1);
        func_800B701C(arg1, arg0, 9);
        M2C_FIELD(sp24, f32 *, 0x3A0) = (f32) M2C_FIELD(arg0, f32 *, 0x24);
        M2C_FIELD(sp24, f32 *, 0x3A8) = (f32) M2C_FIELD(arg0, f32 *, 0x2C);
        M2C_FIELD(arg0, s16 *, 0x1CA) = 0x14;
        func_808B7B70(arg0, &D_808B96B0);
    }
}
