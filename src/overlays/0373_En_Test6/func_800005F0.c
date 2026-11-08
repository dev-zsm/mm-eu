// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0373.h"

void EnTest6_DisableWhiteFillScreen(PlayState *play) {
    M2C_FIELD(play, s8 *, 0x170E9) = 0;
}
