#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0436.h"
void func_800E7BB8(u8 *a, u8 *c);
void func_800E26E8(u8 *play, u8 *p, u8 *c);

void func_80002110(Actor *thisx, PlayState *play) {
    func_800E7BB8(thisx, (u8 *)thisx + 0x144);
    func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x144);
}
