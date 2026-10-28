// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80AA06C0;

void func_8000083C(u8 *arg0, M2C_UNK arg1) {
    f32 sp1C;
    s16 temp_v0;

    sp1C = M2C_FIELD(arg0, f32 *, 0x15C);
    func_80137070(arg0 + 0x144, arg0);
    if (M2C_FIELD(arg0, f32 *, 0x240) <= sp1C) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x16);
        M2C_FIELD(arg0, s16 *, 0x21C) = 3;
        M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_80AA06C0;
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    }
}
