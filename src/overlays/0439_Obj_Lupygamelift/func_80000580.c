// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0439.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_60071B8;

void ObjLupygamelift_Draw(Actor *thisx, PlayState *play) {
    func_800BDD44(play, &D_60071B8, play);
}
