// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0232.h"

s32 func_80137C58(u8 *, f32);
void func_800B8C4C();

void func_80000834(Actor *thisx) {
    if (func_80137C58((u8 *)thisx + 0x14C, 1.0f) != 0 || func_80137C58((u8 *)thisx + 0x14C, 7.0f) != 0) {
        func_800B8C4C(thisx, 0x28EF);
    }
}
