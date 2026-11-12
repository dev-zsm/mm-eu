// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern u8 D_801F48C0[];
extern u32 D_801F48CC;
void func_80093D50(void *mq, u32 msg, u32 flag);

void func_80188124(u32 arg0) {
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, arg0 | 0x4B000000);
    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0x78000000);
}
