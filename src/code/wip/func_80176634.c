// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad0[0x2D1]; u8 rumble[4]; u8 pad2D5[0x47D - 0x2D5]; u8 rumbleEnable; } PadMgr;
extern PadMgr *D_801C9E40;
// unmatched: ROM keeps the table pointer in v1 instead of v0
void PadMgr_RumbleSet(u8 *r) {
    PadMgr **mgr = &D_801C9E40;
    (*mgr)->rumble[0] = r[0];
    (*mgr)->rumble[1] = r[1];
    (*mgr)->rumble[2] = r[2];
    (*mgr)->rumble[3] = r[3];
    (*mgr)->rumbleEnable = 0x18;
}
