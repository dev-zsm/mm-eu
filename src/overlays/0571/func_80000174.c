#include "types.h"
#include "m2c_compat.h"
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *play, u8 *p, u8 *c);

void func_80000174(u8 *a, u8 *play) {
    func_800E7BB8(a, a + 0x190);
    func_800E26E8(play, play + 0x18884, a + 0x190);
}
