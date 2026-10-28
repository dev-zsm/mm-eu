// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80AB2810;
extern f32 D_80AB2814;

void func_800004C4(u8 *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x224);
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x70);
    if (temp_f0 < temp_f2) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f2 * D_80AB2810);
        return;
    }
    if (temp_f2 < (temp_f0 - D_80AB2814)) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f2 + D_80AB2814);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = temp_f0;
}
