// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0390.h"

extern u8 D_80A9EB24[];
extern u8 D_80A9EB28[];
void func_800FF30C();
void func_800B246C();

void func_80003934(s32 arg0, s32 arg1) {
    f32 sp24[3];

    func_800FF30C(sp24, arg0 + 0x3C);
    sp24[1] += 20.0f;
    func_800B246C(arg1, sp24, D_80A9EB24, D_80A9EB28, 0, 0x12C);
}
