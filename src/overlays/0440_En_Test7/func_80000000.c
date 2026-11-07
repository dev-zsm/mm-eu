// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0440.h"

void EnTest7_SetupPlayerCamFunc(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1E5C) = arg1;
}
