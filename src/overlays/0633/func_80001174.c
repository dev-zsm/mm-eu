// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0633.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60063C4;
extern M2C_UNK D_80BF66DC;

void func_80001174(Actor *thisx) {
    func_80137934((u8 *)thisx + 0x144, &D_60063C4, 0xC1200000, thisx);
    M2C_FIELD(thisx, s16 *, 0x18E) = 0x12C;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80BF66DC;
    M2C_FIELD(thisx, f32 *, 0x70) = 5.0f;
}
