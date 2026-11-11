#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0126.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60002B8;
extern M2C_UNK D_808F0E38;

void func_800004FC(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60002B8, 0x40800000, 0, (f32) func_80134AE8(&D_60002B8), 0, -3.0f);
    func_800B8C4C(arg0, 0x39E2);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808F0E38;
}
