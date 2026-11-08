// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0350.h"

void func_80001B74(EnKusa2 *this) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(this, u8 **, 0x1B8);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0) = (f32) M2C_FIELD(this, f32 *, 0x24);
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) (M2C_FIELD(this, f32 *, 0x28) + 20.0f);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(this, f32 *, 0x2C);
    }
}
