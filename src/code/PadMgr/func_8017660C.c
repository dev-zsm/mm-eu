#include "types.h"

extern u8 *D_801C9E40;

void PadMgr_RumbleSetSingle(s32 arg0, s32 arg1) {
    D_801C9E40[arg0 + 0x2D1] = arg1;
    D_801C9E40[0x47D] = 0x18;
}
