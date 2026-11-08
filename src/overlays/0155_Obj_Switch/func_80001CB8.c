// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_5007E00;

void ObjSwitch_DrawRustyFloorSwitch(ObjSwitch *this, PlayState *play) {
    func_800BDD44(play, &D_5007E00, play);
}
