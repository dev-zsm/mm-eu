#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0452.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6009298;
extern M2C_UNK D_80AE4798;

void func_8000112C(u8 *arg0) {
    func_80137788(arg0 + 0x190, &D_6009298, 0xBF800000, (f32) func_80134AE8(&D_6009298), 0.0f, 2, -8.0f);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    func_800B8C4C(arg0, 0x3ADB);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x3EA) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AE4798;
}
