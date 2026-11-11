#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000CE8;
extern M2C_UNK D_8090EE2C;
extern f32 D_80910D1C;

void func_8000097C(u8 *arg0) {
    f32 sp30;
    f32 var_f0;

    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0x2F4) != 0) {
        var_f0 = 1.5f;
    } else {
        var_f0 = D_80910D1C;
    }
    sp30 = var_f0;
    func_80137788(arg0 + 0x144, &D_6000CE8, var_f0, 0, (f32) func_80134AE8(&D_6000CE8), 3, -4.0f);
    M2C_FIELD(arg0, s16 *, 0x2F6) = 0;
    M2C_FIELD(arg0, s16 *, 0x2F8) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090EE2C;
}
