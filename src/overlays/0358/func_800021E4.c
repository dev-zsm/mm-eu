#include "types.h"
#include "m2c_compat.h"

s32 func_80087010();                                /* extern */
extern M2C_UNK D_80A4F744;
extern f32 D_80A507E8;

void func_800021E4(u8 *arg0) {
    if (func_80087010() & 1) {
        M2C_FIELD(arg0, s16 *, 0x370) = 0x800;
    } else {
        M2C_FIELD(arg0, s16 *, 0x370) = -0x800;
    }
    M2C_FIELD(arg0, f32 *, 0x160) = (f32) D_80A507E8;
    M2C_FIELD(arg0, s16 *, 0x368) = 0x11;
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80A4F744;
}
