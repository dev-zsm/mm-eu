#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0124.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000194;
extern M2C_UNK D_808E3BA4;

void func_80000254(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6000194, 0x3F800000, 0, (f32) func_80134AE8(&D_6000194), 2, 0.0f);
    M2C_FIELD(arg0, s16 *, 0x246) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1F4) = &D_808E3BA4;
    func_800B8C4C(arg0, 0x3849);
}
