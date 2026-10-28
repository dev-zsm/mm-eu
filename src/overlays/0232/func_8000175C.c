// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(s32, s16, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_8096E748(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8096F358;
extern M2C_UNK D_8097109C;

void func_8000175C(u8 *arg0, M2C_UNK arg1) {
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 4, 0xC00);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (M2C_FIELD(arg0, f32 *, 0x98) < 250.0f) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 0xB);
        M2C_FIELD(arg0, s16 *, 0x282) = 0x32;
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F358;
    }
    func_8096E748(arg0, 0x41500000);
    func_8096E748(arg0, 0x41980000);
}
