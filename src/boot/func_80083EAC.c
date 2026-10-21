// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_80098ED0[];
extern void func_80083E54(void *a0, s32 a1);
extern void func_80087A44(void *a0, void *a1, s32 a2, s32 a3);

void func_80083EAC(s32 a0, s32 a1) {
    u8 buf[0x100];
    func_80087A44(buf, D_80098ED0, a0, a1);
    func_80083E54(buf, 0);
}
