// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801E6F26;
extern f32 D_80862238;

s32 func_80009DE4(u8 *arg0) {
    f32 temp_f0;
    u8 *temp_v0;

    if (M2C_FIELD(arg0, f32 *, 0x68) < 0.0f) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x8C);
        if ((temp_f0 > 0.0f) && ((M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xA68), f32 *, 0x2C) - temp_f0) < D_80862238) && (M2C_FIELD(arg0, u8 *, 0xB67) != 0) && (D_801E6F26 != 0) && !(M2C_FIELD(arg0, s32 *, 0xA6C) & 0x04000000) && ((temp_v0 = M2C_FIELD(arg0, u8 **, 0xA88), (temp_v0 == NULL)) || !(M2C_FIELD(temp_v0, s32 *, 4) & 0x10000))) {
            return 1;
        }
    }
    return 0;
}
