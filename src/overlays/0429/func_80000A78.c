// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0429.h"

M2C_UNK func_800B701C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80AC4384;

void func_80000A78(u8 *arg0, PlayState *play) {
    func_800B701C(play, arg0, 7, play);
    M2C_FIELD(arg0, s8 *, 0x2AD) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80AC4384;
}
