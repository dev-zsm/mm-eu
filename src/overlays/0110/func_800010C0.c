// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_60019CC;
extern M2C_UNK D_808D0D20;
extern M2C_UNK D_808D0EBC;

void func_800010C0(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60019CC, 0x3F800000, 0x42240000, 42.0f, 2, 5.0f);
    if ((M2C_FIELD(arg0, f32 *, 0x70) < 0.0f) || (&D_808D0D20 != M2C_FIELD(arg0, M2C_UNK **, 0x188))) {
        M2C_FIELD(arg0, s16 *, 0x18E) = 0x1E;
    } else {
        M2C_FIELD(arg0, s16 *, 0x18E) = 0x2D;
    }
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D0EBC;
}
