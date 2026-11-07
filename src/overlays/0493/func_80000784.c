#include "types.h"
#include "m2c_compat.h"
void func_800E0FAC(u8 *a, u8 *b, s32 c, u8 *d);
void func_80102484(u8 *a, u8 *b, s32 c);

void func_80000784(u8 *a, u8 *play, s32 c) {
    func_800E0FAC(play, a + 0x18C, c, play);
    func_80102484(play, play + 0x818, M2C_FIELD(a, s32 *, 0x364));
}
