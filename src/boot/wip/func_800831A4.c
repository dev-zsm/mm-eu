// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u8 pad0[0xF4];
    u32 ra;
    u8 pad1[0x104 - 0xF8];
    u32 sp;
    u8 pad2[0x11C - 0x108];
    u32 pc;
} Thread;

extern void Fault_FillScreenBlack(void);
extern void FaultDrawer_DrawText(s32 a0, s32 a1, void *a2, ...);
extern u32 Fault_ConvertAddress(u32 a0);
extern void FaultDrawer_Printf(void *a0, ...);
extern void Fault_WalkStack(u32 *sp, u32 *pc, u32 *ra);
extern u8 D_80098C10[];
extern u8 D_80098C1C[];
extern u8 D_80098C34[];
extern u8 D_80098C40[];
extern u8 D_80098C4C[];
extern u8 D_800895C0[];

void Fault_DrawStackTrace(Thread *thread, u32 flags) {
    s32 line;
    u32 sp = thread->ra;
    u32 ra = thread->sp;
    u32 pc = thread->pc;
    u32 addr;
    s32 pad[2];

    Fault_FillScreenBlack();
    FaultDrawer_DrawText(0x78, 0x10, D_80098C10);
    FaultDrawer_DrawText(0x24, 0x18, D_80098C1C);
    for (line = 1; line < 22 && (ra != 0 || sp != 0) && pc != (u32)D_800895C0; line++) {
        FaultDrawer_DrawText(0x24, line * 8 + 0x18, D_80098C34, sp, pc);
        if (flags & 1) {
            addr = Fault_ConvertAddress(pc);
            if (addr != 0) {
                FaultDrawer_Printf(D_80098C40, addr);
            }
        } else {
            FaultDrawer_Printf(D_80098C4C);
        }
        Fault_WalkStack(&sp, &pc, &ra);
    }
}
