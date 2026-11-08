// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

extern M2C_UNK D_808640E8;

void EnGirlA_Restock(PlayState *play, EnGirlA *this) {
    M2C_FIELD(this, s16 *, 0x1A0) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x13C) = &D_808640E8;
}
