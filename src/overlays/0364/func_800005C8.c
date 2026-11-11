#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0364.h"

f32 func_8017A870(f32);                         /* extern */
M2C_UNK func_80A5AB98(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80A5B068;

void func_800005C8(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (func_8017A870(1.0f) + 4.0f);
    func_80A5AB98(arg0, 0);
    M2C_FIELD(arg0, s16 *, 0x1EA) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x1C4) = &D_80A5B068;
}
