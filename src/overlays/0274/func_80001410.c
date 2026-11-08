// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0274.h"

void func_809A966C(u8 *, s32, f32);
extern u8 D_809AA924;

void func_80001410(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x2F4) != 0) {
        func_809A966C(arg0, 0, 1.0f);
    } else {
        M2C_FIELD(arg0, s32 *, 0x2F8) = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x29C) = 2;
    M2C_FIELD(arg0, u8 **, 0x284) = &D_809AA924;
}
