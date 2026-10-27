#include "types.h"

extern void func_800897D0(void *, s32);
extern void func_80089FE0(void *, s32, void *, void *, s32, s32);
extern void func_80095950(void *);
extern void func_8018659C(void *);

void Slowly_Init(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_800897D0(a0, 0x1C0);
    a0[0x1B0] = 2;
    a0[0x1B1] = 0;
    *(s32 *)(a0 + 0x1B4) = a2;
    *(s32 *)(a0 + 0x1B8) = a3;
    *(s32 *)(a0 + 0x1BC) = a4;
    func_80089FE0(a0, 2, func_8018659C, a0, a1, 5);
    func_80095950(a0);
}
