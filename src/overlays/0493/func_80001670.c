#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0493.h"
extern struct { u8 pad0[0xF11]; u8 fF11; } D_801E6EF0;
void func_800B8C4C(u8 *a, s32 b);
void func_80B41800(u8 *a, u8 *b);

void func_80001670(u8 *a, u8 *play) {
    if (M2C_FIELD(a, u16 *, 0x32C) & 8) {
        func_800B8C4C(a, 0x294B);
        D_801E6EF0.fF11 |= 4;
        func_80B41800(a, play);
    }
}
