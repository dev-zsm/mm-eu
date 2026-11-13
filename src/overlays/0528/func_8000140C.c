#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0528.h"

M2C_UNK func_80B7B90C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80B7BB7C();                                /* extern */
extern M2C_UNK D_80B7C87C;

void func_8000140C(u8 *arg0, M2C_UNK arg1) {
    if (func_80B7BB7C(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7C87C;
        func_80B7B90C(arg0, 0, 0);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 1.5f;
}
