// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;
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
void Fault_DrawStackTrace(u8 *a0, s32 a1);
void Fault_LogStackTrace(u8 *a0, s32 a1);
void Fault_ProcessClients(void);
void Fault_DrawMemDump(s32 a0, s32 a1, s32 a2, s32 a3);
void Fault_FillScreenRed(void);
void FaultDrawer_DrawText(s32 a0, s32 a1, void *a2, ...);
void Fault_ResumeThread(u8 *a0);

void Fault_ThreadEntry(s32 a0) {
    u8 **s1;
    u8 *s0;
    s32 sp54;

    s1 = &D_8009C220;
    osSetEventMesg(0xA, *s1 + 0x7B0, 1);
    osSetEventMesg(0xC, *s1 + 0x7B0, 2);
    do {
        do {
            osRecvMesg(*s1 + 0x7B0, &sp54, 1);
            if (sp54 == 3) {
                s0 = NULL;
                Fault_UpdatePad();
            } else {
                if (sp54 == 1) {
                    (*s1)[0x7CD] = 1;
                    func_8008198C(D_80098D18);
                } else if (sp54 == 2) {
                    (*s1)[0x7CD] = 2;
                    func_8008198C(D_80098D50);
                } else {
                    (*s1)[0x7CD] = 3;
                    func_8008198C(D_80098D84);
                }
                s0 = (u8 *)__osGetCurrFaultedThread();
                func_8008198C(D_80098DB8, s0);
                if (s0 == NULL) {
                    s0 = (u8 *)Fault_FindFaultedThread();
                    func_8008198C(D_80098DDC, s0);
                }
            }
        } while (s0 == NULL);
        __osSetFpcCsr(__osGetFpcCsr() & ~0xF80);
        *(s32 *)(*s1 + 0x7D0) = (s32)s0;
        while ((*s1)[0x7CE] == 0) {
            Fault_Sleep(0x3E8);
        }
        Fault_Sleep(0x1F4);
        Fault_DisplayFrameBuffer();
        if ((*s1)[0x7CF] != 0) {
            Fault_Wait5Seconds();
        } else {
            Fault_DrawCornerRec(0xF801);
            Fault_WaitForButtonCombo();
        }
        (*s1)[0x7CF] = 1;
        FaultDrawer_SetForeColor(0xFFFF);
        FaultDrawer_SetBackColor(0);
        do {
            Fault_PrintThreadContext(s0);
            Fault_LogThreadContext(s0);
            Fault_WaitForInput();
            Fault_DrawStackTrace(s0, 0);
            Fault_LogStackTrace(s0, 0);
            Fault_WaitForInput();
            Fault_ProcessClients();
            Fault_DrawMemDump(*(s32 *)(s0 + 0x11C) - 0x100, *(s32 *)(s0 + 0xF4), 0, 0);
            Fault_DrawStackTrace(s0, 1);
            Fault_LogStackTrace(s0, 1);
            Fault_WaitForInput();
            Fault_FillScreenRed();
            FaultDrawer_DrawText(0x40, 0x50, D_80098DF8);
            FaultDrawer_DrawText(0x40, 0x5A, D_80098E14);
            FaultDrawer_DrawText(0x40, 0x64, D_80098E30);
            FaultDrawer_DrawText(0x40, 0x6E, D_80098E4C);
            Fault_WaitForInput();
        } while ((*s1)[0x7CC] == 0);
        Fault_ResumeThread(s0);
    } while (1);
}
