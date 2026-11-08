// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0472.h"

s32 func_800B877C();                                /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80B0C490(u8 *, s32);                 /* extern */
extern u8 D_801E7E27;

void func_80001438(Actor *thisx, PlayState *play) {
    if (func_800B877C() != 0) {
        M2C_FIELD(thisx, s32 *, 0x120) = 0;
        func_80B0C490(thisx, play);
        return;
    }
    if (!(D_801E7E27 & 0x20)) {
        func_800B87A0(thisx, play, 0xC, 0x44480000, 100.0f);
        return;
    }
    func_800B87A0(thisx, play, 4, 0x44480000, 100.0f);
}
