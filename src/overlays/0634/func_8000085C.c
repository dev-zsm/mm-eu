#include "types.h"
#include "m2c_compat.h"
typedef struct { u8 pad0[0x1CCC]; u8 *f1CCC; u8 pad1[0x16C68 - 0x1CD0]; u8 f16C68; } PS;
void func_80BF8F7C(u8 *a);

void func_8000085C(u8 *a, PS *play) {
    u8 *p = play->f1CCC;

    if (play->f16C68 == 8) {
        func_80BF8F7C(a);
        M2C_FIELD(p, u32 *, 0xA6C) &= ~0x20;
    }
}
