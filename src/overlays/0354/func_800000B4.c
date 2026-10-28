// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A49304;
extern M2C_UNK D_80A4AAC0;

void func_800000B4(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    func_800BD9E0(arg0 + 0x144, &D_80A4AAC0, 1, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A49304;
}
