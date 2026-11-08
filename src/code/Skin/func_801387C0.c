// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Skin_Setup(struct Skin *skin) {
    M2C_FIELD(skin, s32 *, 0) = 0;
    M2C_FIELD(skin, s32 *, 0x44) = 0;
    M2C_FIELD(skin, s32 *, 0x48) = 0;
}
