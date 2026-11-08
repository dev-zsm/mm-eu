// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0055.h"

s32 KaleidoScope_UpdateQuestStatusPoint(void *pauseCtx, s16 point) {
    M2C_FIELD(pauseCtx, s16 *, 0x23C) = point;
    return 1;
}
