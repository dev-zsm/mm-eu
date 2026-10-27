// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct Node800835EC {
    struct Node800835EC *next;
    void (*fn)(s32, s32);
    s32 unk8;
    s32 unkC;
} Node800835EC;

extern void Fault_FillScreenBlack(void);
extern void FaultDrawer_SetCharPad(s32 a0, s32 a1);
extern void FaultDrawer_Printf(void *a0, s32 a1, Node800835EC *a2, s32 a3, s32 sp10);
extern void Fault_WaitForInput(void);
extern void Fault_DisplayFrameBuffer(void);
extern u8 D_80098CB0[];
extern void *D_8009C220;

void Fault_ProcessClients(void) {
    Node800835EC *node;
    s32 i;

    i = 0;
    node = *(Node800835EC **)((u8 *)D_8009C220 + 0x7D8);
    while (node != NULL) {
        if (node->fn != NULL) {
            Fault_FillScreenBlack();
            FaultDrawer_SetCharPad(-2, 0);
            FaultDrawer_Printf(D_80098CB0, i++, node, node->unk8, node->unkC);
            FaultDrawer_SetCharPad(0, 0);
            node->fn(node->unk8, node->unkC);
            Fault_WaitForInput();
            Fault_DisplayFrameBuffer();
        }
        node = node->next;
    }
}
