// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_801377D0(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_8089A490(u8 *);                      /* extern */
extern M2C_UNK D_6000AF0;
extern M2C_UNK D_60025B4;
extern M2C_UNK D_8089B9C8;
extern M2C_UNK D_8089BB6C;

void func_80001CB8(u8 *arg0) {
    if (&D_8089B9C8 != M2C_FIELD(arg0, M2C_UNK **, 0x284)) {
        func_801377D0(arg0 + 0x144, &D_6000AF0);
    } else {
        M2C_FIELD(arg0, f32 *, 0x154) = (f32) func_80134AE8(&D_60025B4);
    }
    if (M2C_FIELD(arg0, f32 *, 0x70) < 0.0f) {
        M2C_FIELD(arg0, s16 *, 0x290) = 1;
    } else {
        M2C_FIELD(arg0, s16 *, 0x290) = 0;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_8089A490(arg0);
    func_800B8C4C(arg0, 0x3828);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089BB6C;
}
