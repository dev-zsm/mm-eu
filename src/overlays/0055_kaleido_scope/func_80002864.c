// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0055.h"

s32 KaleidoScope_UpdateQuestStatusPoint(u8 *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x23C) = arg1;
    return 1;
}
