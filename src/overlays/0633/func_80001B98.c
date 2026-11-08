// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0633.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80BF5724(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_6000278;
extern M2C_UNK D_80BF7118;

void func_80001B98(Actor *thisx) {
    func_80137934((u8 *)thisx + 0x144, &D_6000278, 0xC0800000, thisx);
    func_80BF5724(thisx, 0xF);
    M2C_FIELD(thisx, s16 *, 0x190) = -0x1000;
    M2C_FIELD(thisx, s16 *, 0x192) = (s16) (M2C_FIELD(thisx, s16 *, 0x92) + 0x8000);
    M2C_FIELD(thisx, s16 *, 0x18E) = 0x28;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80BF7118;
}
