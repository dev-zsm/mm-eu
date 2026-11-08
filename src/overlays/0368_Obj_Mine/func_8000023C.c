// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

s32 ObjMine_AirWater_CheckOC(ObjMine *this) {
    u8 *temp_v0;

    if (M2C_FIELD(this, u8 *, 0x157) & 1) {
        return 1;
    }
    if (M2C_FIELD(this, u8 *, 0x156) & 2) {
        temp_v0 = M2C_FIELD(this, u8 **, 0x150);
        if ((M2C_FIELD(temp_v0, s16 *, 0) == 0x185) && (M2C_FIELD(this, s8 *, 3) == M2C_FIELD(temp_v0, s8 *, 3))) {
            return 1;
        }
    }
    return 0;
}
