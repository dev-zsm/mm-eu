// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80ACC23C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_801E6EF0;
extern s32 D_801E6F08;
extern M2C_UNK D_80ACCC64;

void func_80000AFC(u8 *arg0) {
    s32 var_v0;

    func_80ACC23C(arg0, 2);
    var_v0 = M2C_FIELD(&D_801E6EF0, s32 *, 0x18);
    if ((var_v0 != 3) && (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) != 0)) {
        func_80ACC23C(arg0, 3);
        var_v0 = D_801E6F08;
    }
    if (var_v0 == 3) {
        func_80ACC23C(arg0, 7);
    }
    M2C_FIELD(arg0, s16 *, 0x274) = 0;
    M2C_FIELD(arg0, s16 *, 0x278) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80ACCC64;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
