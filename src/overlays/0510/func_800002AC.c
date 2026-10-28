// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B618A8;
extern M2C_UNK D_80B61D1C;

void func_800002AC(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
    if (&D_80B61D1C == M2C_FIELD(arg0, M2C_UNK **, 0x2AC)) {
        M2C_FIELD(arg0, s16 *, 0x30A) = 0x14;
    } else {
        M2C_FIELD(arg0, s16 *, 0x30A) = 0xA;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B618A8;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
}
