#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60005C4;
extern M2C_UNK D_80897030;
extern M2C_UNK D_80897A58;

void func_80000934(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60005C4, arg0);
    M2C_FIELD(arg0, f32 *, 0x2B8) = 0.0f;
    if (&D_80897A58 == M2C_FIELD(arg0, M2C_UNK **, 0x2A8)) {
        M2C_FIELD(arg0, s8 *, 0x2AD) = (s8) -M2C_FIELD(arg0, s8 *, 0x2AD);
    } else M2C_FIELD(arg0, s8 *, 0x2AD) = func_8008704C() < 0.5f ? 1 : -1;
    M2C_FIELD(arg0, u8 *, 0x478) = (u8) (M2C_FIELD(arg0, u8 *, 0x478) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80897030;
}
