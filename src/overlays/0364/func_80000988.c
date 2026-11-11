#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0364.h"

f32 func_8017A870(f32);                         /* extern */
extern M2C_UNK D_80A5B428;

void func_80000988(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (func_8017A870(1.0f) + 3.0f);
    M2C_FIELD(arg0, s16 *, 0x1EE) = 0;
    M2C_FIELD(arg0, s16 *, 0x1EA) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x1C4) = &D_80A5B428;
    M2C_FIELD(arg0, f32 *, 0x160) = 2.0f;
}
