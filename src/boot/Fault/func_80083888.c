// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_ThreadEntry(void *arg) {
    OSMesg msg;
    u32 pad; /* matching: unused, keeps the layout of the locals */
    OSThread *faultedThread;

    osSetEventMesg(OS_EVENT_CPU_BREAK, &D_8009C220->queue, (OSMesg)FAULT_MSG_CPU_BREAK);
    osSetEventMesg(OS_EVENT_FAULT, &D_8009C220->queue, (OSMesg)FAULT_MSG_FAULT);
    for (;;) {
        do {
            osRecvMesg(&D_8009C220->queue, &msg, OS_MESG_BLOCK);
            if (msg == (OSMesg)FAULT_MSG_CPU_BREAK) {
                D_8009C220->msgId = FAULT_MSG_CPU_BREAK;
                func_8008198C(D_80098D18);
            } else if (msg == (OSMesg)FAULT_MSG_FAULT) {
                D_8009C220->msgId = FAULT_MSG_FAULT;
                func_8008198C(D_80098D50);
            } else if (msg == (OSMesg)FAULT_MSG_UPDATE_PAD) {
                Fault_UpdatePad();
                faultedThread = NULL;
                continue;
            } else {
                D_8009C220->msgId = 3;
                func_8008198C(D_80098D84);
            }
            faultedThread = __osGetCurrFaultedThread();
            func_8008198C(D_80098DB8, faultedThread);
            if (faultedThread == NULL) {
                faultedThread = Fault_FindFaultedThread();
                func_8008198C(D_80098DDC, faultedThread);
            }
        } while (faultedThread == NULL);
        __osSetFpcCsr(__osGetFpcCsr() & ~FPCSR_ENABLES);
        D_8009C220->faultedThread = faultedThread;
        while (!D_8009C220->faultHandlerEnabled) {
            Fault_Sleep(1000);
        }

        Fault_Sleep(500);
        Fault_DisplayFrameBuffer();
        if (D_8009C220->autoScroll) {
            Fault_Wait5Seconds();
        } else {
            Fault_DrawCornerRec(FAULT_COLOR_RED);
            Fault_WaitForButtonCombo();
        }
        D_8009C220->autoScroll = 1;
        FaultDrawer_SetForeColor(FAULT_COLOR_WHITE);
        FaultDrawer_SetBackColor(0);
        do {
            Fault_PrintThreadContext(faultedThread);
            Fault_LogThreadContext(faultedThread);
            Fault_WaitForInput();
            Fault_DrawStackTrace(faultedThread, 0);
            Fault_LogStackTrace(faultedThread, 0);
            Fault_WaitForInput();
            Fault_ProcessClients();
            Fault_DrawMemDump(faultedThread->context.pc - 0x100, (u32)faultedThread->context.sp, 0, 0);
            Fault_DrawStackTrace(faultedThread, 1);
            Fault_LogStackTrace(faultedThread, 1);
            Fault_WaitForInput();
            Fault_FillScreenRed();
            FaultDrawer_DrawText(64, 80, D_80098DF8);
            FaultDrawer_DrawText(64, 90, D_80098E14);
            FaultDrawer_DrawText(64, 100, D_80098E30);
            FaultDrawer_DrawText(64, 110, D_80098E4C);
            Fault_WaitForInput();
        } while (!D_8009C220->exit);
        while (!D_8009C220->exit) {
        }

        Fault_ResumeThread(faultedThread);
    }
}
