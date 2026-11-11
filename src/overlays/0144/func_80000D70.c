#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

s16 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6002484;
extern M2C_UNK D_8090F244;
extern f32 D_80910D24;

void func_80000D70(u8 *arg0) {
    f32 sp34;
    f32 var_f0;
    f32 var_f2;
    s16 temp_v1;

    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0x2F4) != 0) {
        var_f2 = D_80910D24;
    } else {
        var_f2 = 1.0f;
    }
    sp34 = var_f2;
    temp_v1 = func_80134AE8(&D_6002484);
    if (M2C_FIELD(arg0, u8 *, 0x2F4) != 0) {
        var_f0 = 4.0f;
    } else {
        var_f0 = 10.0f;
    }
    func_80137788(arg0 + 0x144, &D_6002484, var_f2, 0, (f32) temp_v1, 3, var_f0);
    M2C_FIELD(arg0, s16 *, 0x2F6) = 0;
    M2C_FIELD(arg0, s16 *, 0x2F8) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090F244;
}
