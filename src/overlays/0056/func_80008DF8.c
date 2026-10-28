// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1EC(s32, u8 *, s32);            /* extern */
s32 func_8082E604(u8 *);                          /* extern */
s32 func_8082E64C(u8 *);                          /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80849190;

void func_80008DF8(u8 *arg0, s32 arg1) {
    s32 var_a2;

    func_80830B44(arg1, arg0, &D_80849190, 1);
    if (M2C_FIELD(arg0, f32 *, 0xB40) < 0.5f) {
        var_a2 = func_8082E604(arg0);
        M2C_FIELD(arg0, f32 *, 0xB40) = 0.0f;
    } else {
        var_a2 = func_8082E64C(arg0);
        M2C_FIELD(arg0, f32 *, 0xB40) = 1.0f;
    }
    M2C_FIELD(arg0, f32 *, 0xB44) = (f32) M2C_FIELD(arg0, f32 *, 0xB40);
    func_8082D1EC(arg1, arg0, var_a2);
    M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
