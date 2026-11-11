// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 46.00 (92 differ, size -5)
#include "generated/mm/fault_ctx.h"

void Fault_SetOptions(void) {
    static u32 sFaultCustomOptions;
    Input* input3 = &sFaultInstance->inputs[3];
    s32 pad;
    uintptr_t pc;
    uintptr_t ra;
    uintptr_t sp;

    if (CHECK_BTN_ALL(input3->press.button, BTN_RESET)) {
        sFaultCustomOptions = !sFaultCustomOptions;
    }

    if (sFaultCustomOptions) {
        pc = gGraphThread.context.pc;
        ra = gGraphThread.context.ra;
        sp = gGraphThread.context.sp;
        if (CHECK_BTN_ALL(input3->cur.button, BTN_R)) {
            static u32 sFaultCopyToLog;

            sFaultCopyToLog = !sFaultCopyToLog;
            FaultDrawer_SetOsSyncPrintfEnabled(sFaultCopyToLog);
        }
        if (CHECK_BTN_ALL(input3->cur.button, BTN_A)) {
            osSyncPrintf("GRAPH PC=%08x RA=%08x STACK=%08x\n", pc, ra, sp);
        }
        if (CHECK_BTN_ALL(input3->cur.button, BTN_B)) {
            FaultDrawer_SetDrawerFrameBuffer(osViGetNextFramebuffer(), SCREEN_WIDTH, SCREEN_HEIGHT);
            Fault_DrawRec(0, 215, 320, 9, 1);
            FaultDrawer_SetCharPad(-2, 0);
            FaultDrawer_DrawText(32, 216, "GRAPH PC %08x RA %08x SP %08x", pc, ra, sp);
        }
    }
}
