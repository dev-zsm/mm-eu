// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, u8 *);              /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_600259C;
extern M2C_UNK D_808BDA38;

void func_800010B4(u8 *arg0, s32 arg1) {
    func_80137828(arg0 + 0x144, &D_600259C, 0xC0400000);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
        M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
        if (arg1 != 0) {
            func_800BE288(arg0, arg0 + 0x27C);
        }
    }
    M2C_FIELD(arg0, s16 *, 0x30) = 0;
    M2C_FIELD(arg0, u8 *, 0x28D) = (u8) (M2C_FIELD(arg0, u8 *, 0x28D) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BDA38;
    func_800B8C4C(arg0, 0x3880);
    func_800B8C4C(arg0, 0x393B);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, func_80134AE8(&D_600259C));
}
