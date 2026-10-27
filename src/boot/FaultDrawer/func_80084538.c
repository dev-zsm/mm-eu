// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;
extern u8 D_80099300[];

void func_8008198C(void *fmt, ...);
void FaultDrawer_DrawRecImpl(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void FaultDrawer_SetCursor(s32 a0, s32 a1);

void FaultDrawer_FillScreen(void) {
    if (D_80096D80[0x35] != 0) {
        func_8008198C(D_80099300);
    }
    FaultDrawer_DrawRecImpl(*(u16 *)(D_80096D80 + 0xC), *(u16 *)(D_80096D80 + 0x8),
                  *(u16 *)(D_80096D80 + 0xE), *(u16 *)(D_80096D80 + 0xA),
                  *(u16 *)(D_80096D80 + 0x12) | 1);
    FaultDrawer_SetCursor(*(u16 *)(D_80096D80 + 0xC), *(u16 *)(D_80096D80 + 0x8));
}
