// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60005C4;
extern M2C_UNK D_80897DC4;

void func_80001724(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60005C4, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B0) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80897DC4;
    M2C_FIELD(arg0, f32 *, 0x2B8) = 0.0f;
}
