// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0056.h"

s32 func_800FEE3C(u8 *, f32, f32, u8 *);
extern u8 D_801E7DFF;

void func_800134E8(u8 *arg0) {
    func_800FEE3C(arg0 + 0xB08, (D_801E7DFF & 2) ? 1.0f : 0.5f, 0.02f, arg0);
}
