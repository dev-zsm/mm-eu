#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0475.h"
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *play, u8 *p, u8 *c);

void func_80000000(u8 *a, u8 *play) {
    func_800E7BB8(a, a + 0x18C);
    func_800E26E8(play, play + 0x18884, a + 0x18C);
}
