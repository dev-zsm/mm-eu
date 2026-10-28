// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8096E6B4(u8 *);                      /* extern */
M2C_UNK func_8096E748(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8096F678;

void func_8000196C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    M2C_FIELD(arg0, u16 *, 0x280) = (u16) (M2C_FIELD(arg0, u16 *, 0x280) & 0xFFF7);
    func_800FFBF8(arg0 + 0x70, 0x40600000, 0x3DCCCCCD, 0x3F000000);
    func_800B680C(arg0);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x28E);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x28E) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x28E);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x28E) = 0x14;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F678;
    }
    func_8096E6B4(arg0);
    func_8096E748(arg0, 0x40400000);
}
