// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u8 pad0[0x7B0];
    u8 queue[0x18];
    s32 msg;
    u8 exit;
    u8 msgId;
    u8 faultHandlerEnabled;
    u8 autoScroll;
    u8 *faultedThread;
} FaultMgr;
extern FaultMgr *D_8009C220;
extern u8 D_80098DF8[];
extern u8 D_80098DDC[];
extern u8 D_80098DB8[];
extern u8 D_80098D18[];
extern u8 D_80098D50[];
extern u8 D_80098D84[];
extern u8 D_80098E14[];
extern u8 D_80098E30[];
extern u8 D_80098E4C[];
void osSetEventMesg(s32 a0, u8 *a1, s32 a2);
void osRecvMesg(u8 *a0, s32 *a1, s32 a2);
void func_8008198C(void *a0, ...);
void Fault_UpdatePad(void);
s32 __osGetCurrFaultedThread(void);
s32 Fault_FindFaultedThread(void);
s32 __osGetFpcCsr(void);
void __osSetFpcCsr(s32 a0);
void Fault_Sleep(s32 a0);
void Fault_DisplayFrameBuffer(void);
void Fault_Wait5Seconds(void);
void Fault_DrawCornerRec(s32 a0);
void Fault_WaitForButtonCombo(void);
void FaultDrawer_SetForeColor(s32 a0);
void FaultDrawer_SetBackColor(s32 a0);
void Fault_PrintThreadContext(u8 *a0);
void Fault_LogThreadContext(u8 *a0);
void Fault_WaitForInput(void);
void Fault_DrawStackTrace(u8 *a0, u32 a1);
void Fault_LogStackTrace(u8 *a0, u32 a1);
void Fault_ProcessClients(void);
void Fault_DrawMemDump(s32 a0, s32 a1, s32 a2, s32 a3);
void Fault_FillScreenRed(void);
void FaultDrawer_DrawText(s32 a0, s32 a1, void *a2, ...);
void Fault_ResumeThread(u8 *a0);
void Fault_ThreadEntry(s32 arg) {
    void *msgs[2];
    u8 *faultedThread;
    void *m;
    osSetEventMesg(0xA, D_8009C220->queue, 1);
    osSetEventMesg(0xC, D_8009C220->queue, 2);
    for (;;) {
        do {
            osRecvMesg(D_8009C220->queue, &msgs[1], 1);
            m = msgs[1];
            if (m == ((void *) 1)) {
                D_8009C220->msgId = 1;
                func_8008198C(D_80098D18);
            } else
                if (m == ((void *) 2)) {
                D_8009C220->msgId = 2;
                func_8008198C(D_80098D50);
            } else
                if (m == ((void *) 3)) {
                Fault_UpdatePad();
                faultedThread = (void *) 0;
                continue;
            } else {
                D_8009C220->msgId = 3;
                func_8008198C(D_80098D84);
            }
            faultedThread = (u8 *) __osGetCurrFaultedThread();
            func_8008198C(D_80098DB8, faultedThread);
            if (faultedThread == ((void *) 0)) {
                faultedThread = (u8 *) Fault_FindFaultedThread();
                func_8008198C(D_80098DDC, faultedThread);
            }
        }
        while (faultedThread == ((void *) 0));
        __osSetFpcCsr(__osGetFpcCsr() & (~0xF80));
        D_8009C220->faultedThread = faultedThread;
        while (!D_8009C220->faultHandlerEnabled) {
            Fault_Sleep(1000);
        }

        Fault_Sleep(500);
        Fault_DisplayFrameBuffer();
        if (D_8009C220->autoScroll) {
            Fault_Wait5Seconds();
        } else {
            Fault_DrawCornerRec(0xF801);
            Fault_WaitForButtonCombo();
        }
        D_8009C220->autoScroll = 1;
        FaultDrawer_SetForeColor(0xFFFF);
        FaultDrawer_SetBackColor(0);
        do {
            Fault_PrintThreadContext(faultedThread);
            Fault_LogThreadContext(faultedThread);
            Fault_WaitForInput();
            Fault_DrawStackTrace(faultedThread, 0);
            Fault_LogStackTrace(faultedThread, 0);
            Fault_WaitForInput();
            Fault_ProcessClients();
            Fault_DrawMemDump((*((s32 *) (faultedThread + 0x11C))) - 0x100, *((s32 *) (faultedThread + 0xF4)), 0, 0);
            Fault_DrawStackTrace(faultedThread, 1);
            Fault_LogStackTrace(faultedThread, 1);
            Fault_WaitForInput();
            Fault_FillScreenRed();
            FaultDrawer_DrawText(0x40, 0x50, D_80098DF8);
            FaultDrawer_DrawText(0x40, 0x5A, D_80098E14);
            FaultDrawer_DrawText(0x40, 0x64, D_80098E30);
            FaultDrawer_DrawText(0x40, 0x6E, D_80098E4C);
            Fault_WaitForInput();
        }
        while (!((((((((((((D_8009C220->exit & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu));
        while (!D_8009C220->exit) {
        }

        Fault_ResumeThread(faultedThread);
    }

}
