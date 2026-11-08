// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0493.h"

s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, s32, s32, f32);  /* extern */
M2C_UNK func_80B40F74(u8 *, s32);                 /* extern */

void func_80000EEC(Actor *thisx, PlayState *play) {
    if (func_800B877C(thisx, play) != 0) {
        M2C_FIELD(thisx, s32 *, 0x120) = 0;
        func_80B40F74(thisx, play);
        func_80B40F74(M2C_FIELD(thisx, u8 **, 0x360), play);
        return;
    }
    func_800B87A0(thisx, play, M2C_FIELD(thisx, s32 *, 0x38C), M2C_FIELD(thisx, s32 *, 0x98), M2C_FIELD(thisx, f32 *, 0x9C));
}
