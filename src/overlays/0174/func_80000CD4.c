#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

M2C_UNK func_800B6490();                            /* extern */
extern f32 D_80941E30;

void func_80000CD4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x70) < 6.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (M2C_FIELD(arg0, f32 *, 0x70) + 1.0f);
    }
    if (D_80941E30 < M2C_FIELD(arg0, f32 *, 0x98)) {
        func_800B6490();
    }
}
