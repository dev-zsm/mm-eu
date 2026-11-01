// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

#define CHECK_BTN_ALL(state, combo) (~((state) | ~(combo)) == 0)

typedef struct {
    u16 cur;
    u8 pad2[0xA];
    u16 press;
} Input;

typedef struct {
    u8 pad0[0x82C];
    Input padInput;
} FaultThreadCtx;

typedef struct {
    u8 padF4[0xF4];
    s32 unkF4;
    u8 pad[0x104 - 0xF8];
    s32 unk104;
    u8 pad108[0x11C - 0x108];
    s32 unk11C;
} FaultRegs;

extern FaultThreadCtx *D_8009C220;
extern FaultRegs D_801EFE88;
extern s32 D_8009C228;
extern s32 D_8009C22C;
extern u8 D_80098CD4[];
extern u8 D_80098CF8[];

void *func_8008ABB0(void);
void FaultDrawer_SetOsSyncPrintfEnabled(s32 a);
void func_8008198C(void *a0, s32 a1, s32 a2, s32 a3);
void Fault_DrawRec(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void FaultDrawer_SetCharPad(s32 a0, s32 a1);
void FaultDrawer_SetDrawerFrameBuffer(void *a0, s32 a1, s32 a2);
void FaultDrawer_DrawText(s32 a0, s32 a1, void *a2, s32 a3, s32 a4, s32 a5);

void Fault_SetOptions(void) {
    Input *input = &D_8009C220->padInput;
    s32 pc;
    s32 sp;
    s32 ra;

    if (CHECK_BTN_ALL(D_8009C220->padInput.press, 0x80)) {
        D_8009C228 = !D_8009C228;
    }
    if (D_8009C228 != 0) {
        pc = D_801EFE88.unk11C;
        sp = D_801EFE88.unk104;
        ra = D_801EFE88.unkF4;
        if (CHECK_BTN_ALL(input->cur, 0x10)) {
            FaultDrawer_SetOsSyncPrintfEnabled(D_8009C22C = !D_8009C22C);
        }
        if (CHECK_BTN_ALL(input->cur, 0x8000)) {
            func_8008198C(D_80098CD4, pc, sp, ra);
        }
        if (CHECK_BTN_ALL(input->cur, 0x4000)) {
            FaultDrawer_SetDrawerFrameBuffer(func_8008ABB0(), 0x140, 0xF0);
            Fault_DrawRec(0, 0xD7, 0x140, 9, 1);
            FaultDrawer_SetCharPad(-2, 0);
            FaultDrawer_DrawText(0x20, 0xD8, D_80098CF8, pc, sp, ra);
        }
    }
}
