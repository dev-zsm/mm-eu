// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_80000318;
extern u8 D_80000500[];
extern u8 D_80025D00[];
extern u8 D_80080060[];
extern u8 D_802006E0[];

void func_80080150(u32 start, u32 end);

void func_800801FC(void) {
    u32 sp18;

    sp18 = D_80000318 + 0x80000000;
    func_80080150(0x80000400, (u32)D_80000500);
    func_80080150((u32)D_80025D00, (u32)D_80080060);
    func_80080150((u32)D_802006E0, sp18);
}
