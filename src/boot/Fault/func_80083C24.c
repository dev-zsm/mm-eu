// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_8009C850[];
extern u8 D_8009C230[0x600]; /* thread stack, ends at D_8009C830 */
extern u8 D_8009C830[];
extern u8 D_80098E68[];
extern void *D_8009C220;
extern u8 D_8009D01E;

extern void bzero(void *a0, s32 a1);
extern void FaultDrawer_Init(void);
extern void FaultDrawer_SetInputCallback(void *a0);
extern void osCreateMesgQueue(void *a0, void *a1, s32 a2);
extern void StackCheck_Init(void *a0, void *a1, void *a2, s32 a3, s32 a4, void *a5);
extern void osCreateThread(void *a0, s32 a1, void *a2, s32 a3, void *a4, s32 a5);
extern void osStartThread(void *a0);
extern void Fault_WaitForInput(void);
extern void Fault_PadCallback(void);
extern void Fault_ThreadEntry(void);

void Fault_Init(void) {
    bzero(D_8009C220 = D_8009C850, 0x848);
    FaultDrawer_Init();
    FaultDrawer_SetInputCallback(Fault_WaitForInput);
    *(u8 *)((u8 *)D_8009C220 + 0x7CC) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CD) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CE) = 0;
    *(u32 *)((u8 *)D_8009C220 + 0x7D0) = 0;
    *(void **)((u8 *)D_8009C220 + 0x7D4) = Fault_PadCallback;
    *(u32 *)((u8 *)D_8009C220 + 0x7D8) = 0;
    *(u8 *)((u8 *)D_8009C220 + 0x7CF) = 0;
    D_8009D01E = 1;
    osCreateMesgQueue((u8 *)D_8009C220 + 0x7B0, (u8 *)D_8009C220 + 0x7C8, 1);
    StackCheck_Init(D_8009C830, D_8009C230, D_8009C230 + sizeof(D_8009C230), 0, 0x100, D_80098E68);
    osCreateThread(D_8009C220, 2, Fault_ThreadEntry, 0, D_8009C830, 0x7F);
    osStartThread(D_8009C220);
}
