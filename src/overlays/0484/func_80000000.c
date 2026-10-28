// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7DFC;
extern M2C_UNK D_80B210CC;

void func_80000000(u8 *arg0) {
    if (D_801E7DFC & 0x20) {
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x10) + 100.0f);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80B210CC;
}
