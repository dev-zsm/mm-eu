#include "types.h"
#include "m2c_compat.h"
extern s32 D_80B35050[];
void func_800E0FAC(u8 *a, u8 *b, u8 *c, u8 *d);

void func_80003210(u8 *a, u8 *play) {
    s32 pad; // matching: unused, moves the next local to the ROM stack slot
    s32 i = M2C_FIELD(a, s16 *, 0x1C) & 7;

    func_800E0FAC(play, a + 0x2A0, a, play);
    D_80B35050[i] = 0;
}
