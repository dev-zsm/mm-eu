// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0182.h"

void EnWeatherTag_SetupAction(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x144) = arg1;
}
