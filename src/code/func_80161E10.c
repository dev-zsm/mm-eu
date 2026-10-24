#include "types.h"

extern s32 D_801EE3D0;
extern s32 *D_801EE3D4;

extern void func_800897D0(s32 *arg0, s32 arg1);

void ShrinkWindow_Init(void) {
    // Going through a pointer to the global reproduces the ROM address computation order.
    s32 **p = &D_801EE3D4;

    *p = &D_801EE3D0;
    func_800897D0(*p, 4);
}
