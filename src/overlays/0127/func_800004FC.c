// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0127.h"

void func_800004FC(Actor *thisx, PlayState *play) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(thisx, u8 **, 0x4A4);
    M2C_FIELD(thisx, s32 *, 0x4AC) = (s32) (M2C_FIELD(thisx, s32 *, 0x4AC) | 0x10);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x4AC) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x4AC) | 0x10);
    }
}
