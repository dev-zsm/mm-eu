// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0188.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_6003B08;

void BgF40Swlift_Draw(Actor *thisx, PlayState *play) {
    func_800BDD44(play, &D_6003B08, play);
}
