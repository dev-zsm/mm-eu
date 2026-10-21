// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_80099300[];

void func_8008198C(void *fmt, ...);
void func_80083F24(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void func_80084434(s32 a0, s32 a1);

void func_80084538(void) {
    if (D_80096D80[0x35] != 0) {
        func_8008198C(D_80099300);
    }
    func_80083F24(*(u16 *)(D_80096D80 + 0xC), *(u16 *)(D_80096D80 + 0x8),
                  *(u16 *)(D_80096D80 + 0xE), *(u16 *)(D_80096D80 + 0xA),
                  *(u16 *)(D_80096D80 + 0x12) | 1);
    func_80084434(*(u16 *)(D_80096D80 + 0xC), *(u16 *)(D_80096D80 + 0x8));
}
