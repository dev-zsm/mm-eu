#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                         /* extern */
extern M2C_UNK D_808CD440;
extern f32 D_808CDA04;

void func_800006A0(u8 *arg0, M2C_UNK arg1) {
    func_800B6564(arg0, (M2C_FIELD(arg0, f32 *, 0x58) * 0.5f) + D_808CDA04);
    M2C_FIELD(arg0, s16 *, 0x16C) = (s16) (M2C_FIELD(arg0, s16 *, 0x16C) + 1);
    if (M2C_FIELD(arg0, s16 *, 0x16C) >= 3) {
        M2C_FIELD(arg0, M2C_UNK **, 0x178) = &D_808CD440;
    }
}
