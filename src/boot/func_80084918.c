// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_80096D84[];
extern u8 D_8009D0A0[];
extern u32 D_80000318;
void func_80091460(void *a0, void *a1, s32 a2);

void func_80084918(void) {
    D_80096D80 = D_8009D0A0;
    func_80091460(D_80096D84, D_80096D80, 0x3C);
    *(u32 *)D_80096D80 = (D_80000318 | 0x80000000) + 0xFFFDA800;
}
