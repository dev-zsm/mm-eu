// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void TitleCard_ContextInit(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s8 *, 0xA) = 0;
    M2C_FIELD(arg1, s8 *, 0xB) = 0;
    M2C_FIELD(arg1, s16 *, 0xE) = 0;
    M2C_FIELD(arg1, s16 *, 0xC) = 0;
}
