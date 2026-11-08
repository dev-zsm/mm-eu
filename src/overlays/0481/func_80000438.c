// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0481.h"

extern M2C_UNK D_80B1C158;
extern M2C_UNK D_80B1C22C;

void func_80000438(Actor *thisx) {
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
    if (&D_80B1C158 != M2C_FIELD(thisx, M2C_UNK **, 0x144)) {
        M2C_FIELD(thisx, s16 *, 0x21E) = 0;
        M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80B1C22C;
        M2C_FIELD(thisx, f32 *, 0x74) = -2.0f;
    }
}
