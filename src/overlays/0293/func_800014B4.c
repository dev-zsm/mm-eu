// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_809F1540(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_809F2B94(u8 *, s32);                 /* extern */
extern M2C_UNK D_6008268;
extern M2C_UNK D_809F21D0;
extern M2C_UNK D_809F5590;

void func_800014B4(u8 *arg0, s32 arg1) {
    s16 sp1E;

    sp1E = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x15C);
    if (func_80134AE8(&D_6008268) == sp1E) {
        func_809F1540(arg0 + 0x144, &D_809F5590, 2);
        func_809F15DC(arg0, &D_809F21D0);
    }
    func_809F2B94(arg0, arg1);
}
