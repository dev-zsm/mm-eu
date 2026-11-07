// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0504.h"

extern M2C_UNK D_80B5445C;

void BgKin2Picture_SetupFall(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x23B) = 0;
    M2C_FIELD(arg0, s16 *, 0x238) = 0;
    M2C_FIELD(arg0, s8 *, 0x23A) = 4;
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_80B5445C;
}
