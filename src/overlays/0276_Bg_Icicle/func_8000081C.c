// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0276.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_60000D0;

void BgIcicle_Draw(Actor *thisx, PlayState *play) {
    func_800BDD44(play, &D_60000D0, play);
}
