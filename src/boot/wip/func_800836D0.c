// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;
extern u8 D_801EFE88[];
extern s32 D_8009C228;
extern s32 D_8009C22C;
extern u8 D_80098CD4[];
extern u8 D_80098CF8[];

s32 func_8008ABB0(void);
void FaultDrawer_SetOsSyncPrintfEnabled(void);
void func_8008198C(void *a0, s32 a1, s32 a2, s32 a3);
void Fault_DrawRec(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void FaultDrawer_SetCharPad(s32 a0, s32 a1);
void FaultDrawer_SetDrawerFrameBuffer(s32 a0, s32 a1, s32 a2);
void FaultDrawer_DrawText(s32 a0, s32 a1, void *a2, s32 a3, s32 a4, s32 a5);

void Fault_SetOptions(void) {
    u8 *t0;
    u8 *v3;
    s32 s2C;
    s32 s28;
    s32 s24;

    t0 = D_8009C220;
    if (~(*(u16 *)(t0 + 0x838) | ~0x80) == 0) {
        D_8009C228 = (D_8009C228 == 0);
    }
    t0 += 0x82C;
    if (D_8009C228 == 0) {
        return;
    }
    v3 = D_801EFE88;
    s2C = *(s32 *)(v3 + 0x11C);
    s28 = *(s32 *)(v3 + 0x104);
    s24 = *(s32 *)(v3 + 0xF4);
    if (~(*(u16 *)t0 | ~0x10) == 0) {
        D_8009C22C = (D_8009C22C == 0);
        FaultDrawer_SetOsSyncPrintfEnabled();
    }
    if (~(*(u16 *)t0 | ~0x8000) == 0) {
        func_8008198C(D_80098CD4, s2C, s28, s24);
    }
    if (~(*(u16 *)t0 | ~0x4000) == 0) {
        FaultDrawer_SetDrawerFrameBuffer(func_8008ABB0(), 0x140, 0xF0);
        Fault_DrawRec(0, 0xD7, 0x140, 9, 1);
        FaultDrawer_SetCharPad(-2, 0);
        FaultDrawer_DrawText(0x20, 0xD8, D_80098CF8, s2C, s28, s24);
    }
}
