// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0249.h"

f32 func_8017A844(f32);
void func_800B8C4C();

void func_800004A0(Actor *thisx) {
    if ((s32)func_8017A844(2.0f) == 0) {
        func_800B8C4C(thisx, 0x6918);
        return;
    }
    func_800B8C4C(thisx, 0x6919);
}
