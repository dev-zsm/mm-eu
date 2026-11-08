// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0299.h"

void func_8000125C(ObjFlowerpot *this, PlayState *play) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(this, u8 *, 0x1EA);
    if (!(temp_v0 & 4) && (M2C_FIELD(this, s8 *, 0x1EC) != M2C_FIELD(play, s8 *, 0x186E0))) {
        M2C_FIELD(this, u8 *, 0x1EA) = (u8) (temp_v0 | 4);
    }
}
