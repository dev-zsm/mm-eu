#ifndef FAULT_H
#define FAULT_H

#include "ultra64.h"
#include "irqmgr.h"
#include "libultra_libc.h"
#include "padutils.h"
#include "stackcheck.h"
#include "faultdrawer.h"

/* Fault handler: a high-priority thread that wakes up on a CPU fault or a break and shows the state of the faulted
   thread on screen, followed by the pages of the registered clients. */

#define OS_EVENT_CPU_BREAK 10
#define OS_EVENT_FAULT 12

/* OSThread.flags */
#define OS_FLAG_CPU_BREAK 0x0001
#define OS_FLAG_FAULT 0x0002

#define OS_IM_NONE 0x00000001

/* osViSetSpecialFeatures */
#define OS_VI_GAMMA_OFF 0x0002
#define OS_VI_DITHER_FILTER_ON 0x0040

/* Messages received by the fault thread; the first two are the events it registers for. */
#define FAULT_MSG_CPU_BREAK 1
#define FAULT_MSG_FAULT 2
#define FAULT_MSG_UPDATE_PAD 3

/* Controller buttons as the fault handler reads them. */
#define BTN_A 0x8000
#define BTN_B 0x4000
#define BTN_Z 0x2000
#define BTN_START 0x1000
#define BTN_DUP 0x0800
#define BTN_DDOWN 0x0400
#define BTN_DLEFT 0x0200
#define BTN_DRIGHT 0x0100
#define BTN_RESET 0x0080
#define BTN_L 0x0020
#define BTN_R 0x0010
#define BTN_CUP 0x0008
#define BTN_CDOWN 0x0004
#define BTN_CLEFT 0x0002
#define BTN_CRIGHT 0x0001

#define CHECK_BTN_ALL(state, combo) (~((state) | ~(combo)) == 0)

/* Low 32 bits of a 64-bit register saved in a thread context (big endian). */
#define LOW_WORD(reg) (((u32 *)&(reg))[1])

/* First of the six FPCSR cause bits (unimplemented operation); the others follow in the lower bits. */
#define FPCSR_CAUSE_UNIMPLEMENTED 0x00020000
#define FPCSR_NUM_CAUSES 6
#define FPCSR_ENABLES 0x00000F80

/* Called with the two arguments given when the client was registered; draws its page of the fault screen. */
typedef void (*FaultClientCallback)(void *arg0, void *arg1);

typedef struct FaultClient {
    /* 0x00 */ struct FaultClient *next;
    /* 0x04 */ FaultClientCallback callback;
    /* 0x08 */ void *arg0;
    /* 0x0C */ void *arg1;
} FaultClient;

/* Converts an address to a printable value (0 when it does not know the address). */
typedef u32 (*FaultAddrConvCallback)(u32 addr, void *arg);

typedef struct FaultAddrConvClient {
    /* 0x00 */ struct FaultAddrConvClient *next;
    /* 0x04 */ FaultAddrConvCallback callback;
    /* 0x08 */ void *arg;
} FaultAddrConvClient;

typedef struct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ u8 pad1B0[0x600];
    /* 0x7B0 */ OSMesgQueue queue;
    /* 0x7C8 */ OSMesg msg[1];
    /* 0x7CC */ u8 exit;
    /* 0x7CD */ u8 msgId;
    /* 0x7CE */ u8 faultHandlerEnabled;
    /* 0x7CF */ u8 autoScroll;               /* pages advance by themselves */
    /* 0x7D0 */ OSThread *faultedThread;
    /* 0x7D4 */ void (*padCallback)(Input *input);
    /* 0x7D8 */ FaultClient *clients;
    /* 0x7DC */ FaultAddrConvClient *addrConvClients;
    /* 0x7E0 */ u8 pad7E0[4];
    /* 0x7E4 */ Input padInput[4];
    /* 0x844 */ void *fb;                    /* frame buffer set by Fault_SetFrameBuffer, NULL for the current one */
} FaultMgr;

extern FaultMgr *D_8009C220;          /* the fault handler state */
extern f32 D_8009C224;                /* shown as seconds under the thread context when not 0 (likely) */
extern FaultMgr D_8009C850;
extern u8 D_8009C230[0x600];          /* stack of the fault thread */
extern StackEntry D_8009C830;         /* follows the stack, whose top it marks */
extern u8 D_8009D01E;

extern const char *D_80096D20[];      /* names of the exception codes */
extern const char *D_80096D68[];      /* names of the FPCSR cause bits */

/* Messages and formats, by address */
extern const char D_8009877C[];
extern const char D_800987FC[];
extern const char D_80098848[];
extern const char D_80098858[];
extern const char D_80098890[];
extern const char D_800988A0[];
extern const char D_800988A8[];
extern const char D_800988AC[];
extern const char D_800988BC[];
extern const char D_800988C4[];
extern const char D_800988D8[];
extern const char D_800988F4[];
extern const char D_80098910[];
extern const char D_8009892C[];
extern const char D_80098948[];
extern const char D_80098964[];
extern const char D_80098980[];
extern const char D_8009899C[];
extern const char D_800989B8[];
extern const char D_800989D4[];
extern const char D_800989F0[];
extern const char D_80098A10[];
extern const char D_80098A14[];
extern const char D_80098A18[];
extern const char D_80098A1C[];
extern const char D_80098A20[];
extern const char D_80098A24[];
extern const char D_80098A28[];
extern const char D_80098A2C[];
extern const char D_80098A30[];
extern const char D_80098A34[];
extern const char D_80098A40[];
extern const char D_80098A44[];
extern const char D_80098A5C[];
extern const char D_80098A7C[];
extern const char D_80098A9C[];
extern const char D_80098ABC[];
extern const char D_80098ADC[];
extern const char D_80098AFC[];
extern const char D_80098B1C[];
extern const char D_80098B3C[];
extern const char D_80098B5C[];
extern const char D_80098B7C[];
extern const char D_80098B9C[];
extern const char D_80098BBC[];
extern const char D_80098BC0[];
extern const char D_80098BC4[];
extern const char D_80098BC8[];
extern const char D_80098BCC[];
extern const char D_80098BD0[];
extern const char D_80098BD4[];
extern const char D_80098BD8[];
extern const char D_80098BDC[];
extern const char D_80098BE0[];
extern const char D_80098BE4[];
extern const char D_80098BEC[];
extern const char D_80098BF8[];
extern const char D_80098C00[];
extern const char D_80098C08[];
extern const char D_80098CB0[];
extern const char D_80098D18[];
extern const char D_80098D50[];
extern const char D_80098D84[];
extern const char D_80098DB8[];
extern const char D_80098DDC[];
extern const char D_80098DF8[];
extern const char D_80098E14[];
extern const char D_80098E30[];
extern const char D_80098E4C[];
extern const char D_80098E68[];
extern const char D_80098E70[];
extern const char D_80098E88[];
extern const char D_80098E8C[];
extern const char D_80098E94[];
extern const char D_80098E98[];
extern const char D_80098EA0[];
extern const char D_80098EB8[];
extern const char D_80098EBC[];
extern const char D_80098EC4[];
extern const char D_80098EC8[];
extern const char D_80098ED0[];
extern const char D_800992E0[];
extern const char D_800992E4[];
extern const char D_800992EC[];
extern const char D_800992F4[];
extern const char D_80099300[];

/* Routines of other modules */
void func_8008198C(const char *fmt, ...);   /* formatted output to the debug port */
void func_80081A50(FaultClient *client, FaultClientCallback callback, void *arg0, void *arg1); /* add a client */
void func_800819E0(u32 msec);               /* busy wait */
void func_80177194(Input *input, s32 gamepad);  /* PadMgr_GetInput2 of the code segment: boot links without its names */
void *func_8008ABB0(void);                  /* frame buffer the video interface will show next */
u32 __osGetFpcCsr(void);
u32 __osSetFpcCsr(u32 value);
void osInvalICache(void *addr, u32 size);
void osWritebackDCacheAll(void);

void Fault_RemoveClient(FaultClient *client);
void Fault_RemoveAddrConvClient(FaultAddrConvClient *client);
u32 Fault_ConvertAddress(u32 addr);
void Fault_Sleep(u32 msec);
void Fault_PadCallback(Input *input);
void Fault_UpdatePadImpl(void);
s32 Fault_WaitForInputImpl(void);
void Fault_WaitForInput(void);
void Fault_DrawRec(s32 x, s32 y, s32 w, s32 h, u16 color);
void Fault_FillScreenBlack(void);
void Fault_FillScreenRed(void);
void Fault_DrawCornerRec(u16 color);
void Fault_PrintFReg(s32 index, f32 *value);
void Fault_LogFReg(s32 index, f32 *value);
void Fault_PrintFPCSR(u32 value);
void Fault_LogFPCSR(u32 value);
void Fault_PrintThreadContext(OSThread *thread);
void Fault_LogThreadContext(OSThread *thread);
OSThread *Fault_FindFaultedThread(void);
void Fault_Wait5Seconds(void);
void Fault_WaitForButtonCombo(void);
void Fault_DrawMemDumpContents(const char *title, u32 addr, u32 arg2);
void Fault_DrawMemDump(u32 pc, u32 sp, u32 cLeftJump, u32 cDownJump);
void Fault_DrawStackTrace(OSThread *thread, u32 flags);
void Fault_LogStackTrace(OSThread *thread, u32 flags);
void Fault_ResumeThread(OSThread *thread);
void Fault_DisplayFrameBuffer(void);
void Fault_ProcessClients(void);
void Fault_SetOptions(void);
void Fault_UpdatePad(void);
void Fault_ThreadEntry(void *arg);
void Fault_SetFrameBuffer(void *fb, u16 w, u16 h);
void Fault_Init(void);
void Fault_HangupFaultClient(const char *exp1, const char *exp2);

#endif
