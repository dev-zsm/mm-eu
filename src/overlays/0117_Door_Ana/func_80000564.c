// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0117.h"

M2C_UNK func_800BDDC0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_5000C40;

void DoorAna_Draw(Actor *thisx, PlayState *play) {
    func_800BDDC0(play, &D_5000C40, play);
}
