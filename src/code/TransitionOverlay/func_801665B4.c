// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void TransitionOverlay_SetSegment(struct TransitionOverlay *overlayEntry, void *vramStart, void *vramEnd, u32 vromStart, u32 vromEnd) {
    M2C_FIELD(overlayEntry, s32 *, 4) = vramStart;
    M2C_FIELD(overlayEntry, s32 *, 8) = vramEnd;
    M2C_FIELD(overlayEntry, s32 *, 0xC) = vromStart;
    M2C_FIELD(overlayEntry, s32 *, 0x10) = vromEnd;
}
