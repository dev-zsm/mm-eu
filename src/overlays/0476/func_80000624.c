// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000A60;
extern M2C_UNK D_80B11A94;

void func_80000624(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6000A60, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B11A94;
    M2C_FIELD(arg0, s16 *, 0x18E) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
}
