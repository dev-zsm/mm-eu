// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0624.h"

void func_8000064C(ObjUsiyane *this, PlayState *play) {
    M2C_FIELD(this, s32 *, 0x164) = -1;
}
