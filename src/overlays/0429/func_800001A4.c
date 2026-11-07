#include "types.h"
#include "m2c_compat.h"
extern struct { u8 pad0[0xF37]; u8 fF37; u8 pad1[0x2E9C]; u8 f3DD4; } D_801E6EF0;
void func_800B5BA4(u8 *a, s32 b);

void func_800001A4(u8 *a, u8 *play) {
    func_800B5BA4(play, 5);
    if (M2C_FIELD(a, u8 *, 0x2AD) == 0) {
        D_801E6EF0.fF37 &= 0xFE;
        D_801E6EF0.f3DD4 = 5;
    }
}
