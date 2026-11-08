#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0587.h"
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *play, u8 *p, u8 *c);

void func_80000140(u8 *a, u8 *play) {
    u8 *c = a + 0x18C;

    func_800E7BB8(a, c);
    func_800E26E8(play, play + 0x18884, c);
}
