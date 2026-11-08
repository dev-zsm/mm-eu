// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8096E6B4(u8 *);                      /* extern */
M2C_UNK func_8096E748(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8096F678;

void func_8000196C(Actor *thisx, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    M2C_FIELD(thisx, u16 *, 0x280) = (u16) (M2C_FIELD(thisx, u16 *, 0x280) & 0xFFF7);
    func_800FFBF8((u8 *)thisx + 0x70, 0x40600000, 0x3DCCCCCD, 0x3F000000);
    func_800B680C(thisx);
    temp_v0 = M2C_FIELD(thisx, s16 *, 0x28E);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(thisx, s16 *, 0x28E) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(thisx, s16 *, 0x28E);
    }
    if (var_v1 == 0) {
        M2C_FIELD(thisx, s16 *, 0x28E) = 0x14;
        M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_8096F678;
    }
    func_8096E6B4(thisx);
    func_8096E748(thisx, 0x40400000);
}
