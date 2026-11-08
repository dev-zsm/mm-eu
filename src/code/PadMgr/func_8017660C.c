#include "types.h"
#include "generated/code_funcs.h"

extern u8 *D_801C9E40;

void PadMgr_RumbleSetSingle(s32 port, s32 enable) {
    D_801C9E40[port + 0x2D1] = enable;
    D_801C9E40[0x47D] = 0x18;
}
