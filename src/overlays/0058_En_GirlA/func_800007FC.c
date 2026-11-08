// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

extern s16 D_801E6F2A;

s32 EnGirlA_CanBuySword(PlayState *play, EnGirlA *this) {
    if (D_801E6F2A < M2C_FIELD(play, s32 *, 0x16978)) {
        return 4;
    }
    return 0;
}
