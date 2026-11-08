// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0179.h"

s32 func_800B877C(u8 *);                          /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80948100(u8 *, s32);                 /* extern */
extern u8 D_801E7DFE;

void func_80001E80(Actor *thisx, PlayState *play) {
    if (func_800B877C(thisx) != 0) {
        M2C_FIELD(thisx, s32 *, 0x120) = 0;
        func_80948100(thisx, play);
    } else if ((M2C_FIELD(thisx, u16 *, 0x552) == 0x2880) && !(D_801E7DFE & 0x80)) {
        func_800B87A0(thisx, play, 0xC, 0x43FA0000, 100.0f);
    } else {
        func_800B87A0(thisx, play, 5, 0x43FA0000, 100.0f);
    }
    M2C_FIELD(M2C_FIELD(thisx, u8 **, 0x124), s16 *, 0x118) = 0xA;
}
