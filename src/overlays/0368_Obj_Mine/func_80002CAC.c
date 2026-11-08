// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

void ObjMine_AirWater_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x1A4)();
}
