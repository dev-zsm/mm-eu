// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0360.h"

s32 func_800B877C();                                /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80A54BEC(u8 *, s32);                 /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000D44(Actor *thisx, PlayState *play) {
    if (func_800B877C() != 0) {
        if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) & 1)) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) | 1);
        }
        M2C_FIELD(thisx, s32 *, 0x120) = 0;
        func_80A54BEC(thisx, play);
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) & 1) {
        func_800B87A0(thisx, play, 5, 0x43FA0000, 100.0f);
        return;
    }
    func_800B87A0(thisx, play, 0xC, 0x43FA0000, 100.0f);
}
