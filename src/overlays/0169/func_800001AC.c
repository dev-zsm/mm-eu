// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0169.h"

void func_801520F8();
extern u8 D_801C2D71;
extern u8 D_801E6F60[];

void func_800001AC(s32 arg0) {
    if (D_801E6F60[D_801C2D71] == 0x39) {
        func_801520F8(arg0, 0x2E);
    }
    func_801520F8(arg0, 0x10);
}
