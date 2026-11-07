#include "types.h"
#include "m2c_compat.h"
void func_800BFE24(s32 a, s32 b, s32 c, s32 d, u8 *e);
void func_8018322C(u8 *a, u8 *b, s32 c);

void func_80000370(u8 *a) {
    s32 pad; // matching: unused, moves the buffer to the ROM stack offset
    u8 sp2C[0x40];

    func_800BFE24(M2C_FIELD(a, s32 *, 0x80), M2C_FIELD(a, s32 *, 0x24), M2C_FIELD(a, s32 *, 0x88), M2C_FIELD(a, s32 *, 0x2C), sp2C);
    func_8018322C(sp2C, a + 0xBC, 0);
}
