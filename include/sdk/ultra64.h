#ifndef ULTRA64_H
#define ULTRA64_H

#include "types.h"

/* Operating system types of libultra. Offsets are those of the ROM: each field is used at that offset by the
 * verified functions of src/boot/libultra/os. */

typedef s32 OSPri;
typedef s32 OSId;
typedef u32 OSIntMask;
typedef u64 OSTime;
typedef void *OSMesg;

#define OS_MESG_NOBLOCK 0
#define OS_MESG_BLOCK 1

#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8

#define OS_IM_ALL 0x003FFF01
#define RCP_IMASK 0x003F0000
#define SR_IE 0x00000001
#define SR_EXL 0x00000002
#define SR_IMASK 0x0000FF00
#define FPCSR_FS 0x01000000
#define FPCSR_EV 0x00000800

typedef union {
    struct {
        f32 f_odd;
        f32 f_even;
    } f;
    f64 d;
} __OSfp;

typedef struct {
    /* 0x000 */ u64 at;
    /* 0x008 */ u64 v0;
    /* 0x010 */ u64 v1;
    /* 0x018 */ u64 a0;
    /* 0x020 */ u64 a1;
    /* 0x028 */ u64 a2;
    /* 0x030 */ u64 a3;
    /* 0x038 */ u64 t0;
    /* 0x040 */ u64 t1;
    /* 0x048 */ u64 t2;
    /* 0x050 */ u64 t3;
    /* 0x058 */ u64 t4;
    /* 0x060 */ u64 t5;
    /* 0x068 */ u64 t6;
    /* 0x070 */ u64 t7;
    /* 0x078 */ u64 s0;
    /* 0x080 */ u64 s1;
    /* 0x088 */ u64 s2;
    /* 0x090 */ u64 s3;
    /* 0x098 */ u64 s4;
    /* 0x0A0 */ u64 s5;
    /* 0x0A8 */ u64 s6;
    /* 0x0B0 */ u64 s7;
    /* 0x0B8 */ u64 t8;
    /* 0x0C0 */ u64 t9;
    /* 0x0C8 */ u64 gp;
    /* 0x0D0 */ u64 sp;
    /* 0x0D8 */ u64 s8;
    /* 0x0E0 */ u64 ra;
    /* 0x0E8 */ u64 lo;
    /* 0x0F0 */ u64 hi;
    /* 0x0F8 */ u32 sr;
    /* 0x0FC */ u32 pc;
    /* 0x100 */ u32 cause;
    /* 0x104 */ u32 badvaddr;
    /* 0x108 */ u32 rcp;
    /* 0x10C */ u32 fpcsr;
    /* 0x110 */ __OSfp fp0;
    /* 0x118 */ __OSfp fp2;
    /* 0x120 */ __OSfp fp4;
    /* 0x128 */ __OSfp fp6;
    /* 0x130 */ __OSfp fp8;
    /* 0x138 */ __OSfp fp10;
    /* 0x140 */ __OSfp fp12;
    /* 0x148 */ __OSfp fp14;
    /* 0x150 */ __OSfp fp16;
    /* 0x158 */ __OSfp fp18;
    /* 0x160 */ __OSfp fp20;
    /* 0x168 */ __OSfp fp22;
    /* 0x170 */ __OSfp fp24;
    /* 0x178 */ __OSfp fp26;
    /* 0x180 */ __OSfp fp28;
    /* 0x188 */ __OSfp fp30;
} __OSThreadContext;

typedef struct OSThread {
    /* 0x000 */ struct OSThread *next;
    /* 0x004 */ OSPri priority;
    /* 0x008 */ struct OSThread **queue;
    /* 0x00C */ struct OSThread *tlnext;
    /* 0x010 */ u16 state;
    /* 0x012 */ u16 flags;
    /* 0x014 */ OSId id;
    /* 0x018 */ s32 fp;
    /* 0x01C */ void *thprof;
    /* 0x020 */ __OSThreadContext context;
} OSThread;

typedef struct {
    /* 0x00 */ OSThread *mtqueue;
    /* 0x04 */ OSThread *fullqueue;
    /* 0x08 */ s32 validCount;
    /* 0x0C */ s32 first;
    /* 0x10 */ s32 msgCount;
    /* 0x14 */ OSMesg *msg;
} OSMesgQueue;

typedef struct OSTimer {
    /* 0x00 */ struct OSTimer *next;
    /* 0x04 */ struct OSTimer *prev;
    /* 0x08 */ OSTime interval;
    /* 0x10 */ OSTime value;
    /* 0x18 */ OSMesgQueue *mq;
    /* 0x1C */ OSMesg msg;
} OSTimer;

/* Cartridge interface */

#define OS_READ 0
#define OS_WRITE 1

#define OS_MESG_PRI_NORMAL 0
#define OS_MESG_PRI_HIGH 1

#define OS_MESG_TYPE_LOOPBACK 10
#define OS_MESG_TYPE_DMAREAD 11
#define OS_MESG_TYPE_DMAWRITE 12
#define OS_MESG_TYPE_EDMAREAD 15
#define OS_MESG_TYPE_EDMAWRITE 16

#define K0BASE 0x80000000
#define K1BASE 0xA0000000
#define K2BASE 0xC0000000
#define IS_KSEG0(x) ((u32)(x) >= K0BASE && (u32)(x) < K1BASE)
#define IS_KSEG1(x) ((u32)(x) >= K1BASE && (u32)(x) < K2BASE)
#define K0_TO_PHYS(x) ((u32)(x) & 0x1FFFFFFF)
#define K1_TO_PHYS(x) ((u32)(x) & 0x1FFFFFFF)

#define IO_READ(addr) (*(volatile u32 *)(addr))
#define IO_WRITE(addr, data) (*(volatile u32 *)(addr) = (u32)(data))

#define PI_DRAM_ADDR_REG 0xA4600000
#define PI_CART_ADDR_REG 0xA4600004
#define PI_RD_LEN_REG 0xA4600008
#define PI_WR_LEN_REG 0xA460000C
#define PI_STATUS_REG 0xA4600010
#define PI_BSD_DOM1_LAT_REG 0xA4600014
#define PI_BSD_DOM1_PWD_REG 0xA4600018
#define PI_BSD_DOM1_PGS_REG 0xA460001C
#define PI_BSD_DOM1_RLS_REG 0xA4600020
#define PI_BSD_DOM2_LAT_REG 0xA4600024
#define PI_BSD_DOM2_PWD_REG 0xA4600028
#define PI_BSD_DOM2_PGS_REG 0xA460002C
#define PI_BSD_DOM2_RLS_REG 0xA4600030

#define PI_STATUS_DMA_BUSY 0x01
#define PI_STATUS_IO_BUSY 0x02

typedef struct {
    /* 0x00 */ s32 errStatus;
    /* 0x04 */ void *dramAddr;
    /* 0x08 */ void *C2Addr;
    /* 0x0C */ u32 sectorSize;
    /* 0x10 */ s32 C1ErrNum;
    /* 0x14 */ s32 C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
    /* 0x00 */ u32 cmdType;
    /* 0x04 */ u16 transferMode;
    /* 0x06 */ u16 blockNum;
    /* 0x08 */ s32 sectorNum;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 bmCtlShadow;
    /* 0x14 */ u32 seqCtlShadow;
    /* 0x18 */ __OSBlockInfo block[2];
} __OSTranxInfo;

typedef struct OSPiHandle {
    /* 0x00 */ struct OSPiHandle *next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 relDuration;
    /* 0x08 */ u8 pulse;
    /* 0x09 */ u8 domain;
    /* 0x0C */ u32 baseAddress;
    /* 0x10 */ u32 speed;
    /* 0x14 */ __OSTranxInfo transferInfo;
} OSPiHandle;

typedef struct {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8 pri;
    /* 0x03 */ u8 status;
    /* 0x04 */ OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    /* 0x00 */ OSIoMesgHdr hdr;
    /* 0x08 */ void *dramAddr;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 size;
    /* 0x14 */ OSPiHandle *piHandle;
} OSIoMesg;

typedef struct {
    /* 0x00 */ s32 active;
    /* 0x04 */ OSThread *thread;
    /* 0x08 */ OSMesgQueue *cmdQueue;
    /* 0x0C */ OSMesgQueue *evtQueue;
    /* 0x10 */ OSMesgQueue *acsQueue;
    /* 0x14 */ s32 (*dma)(s32 direction, u32 devAddr, void *dramAddr, u32 size);
    /* 0x18 */ s32 (*edma)(OSPiHandle *handle, s32 direction, u32 devAddr, void *dramAddr, u32 size);
} OSDevMgr;

/* End marker of every thread queue: an empty queue head points at it. */
typedef struct {
    OSThread *next;
    OSPri priority;
} __OSThreadTail;

typedef s32 OSEvent;
typedef u32 OSHWIntr;

#define OS_EVENT_PRENMI 14

typedef struct {
    /* 0x0 */ OSMesgQueue *messageQueue;
    /* 0x4 */ OSMesg message;
} __OSEventState;

typedef struct {
    /* 0x0 */ s32 (*handler)(void);
    /* 0x4 */ void *stackEnd;
} __OSHwInterrupt;

extern __OSThreadTail D_80098000;
extern OSThread *D_80098008;  /* run queue */
extern OSThread *D_8009800C;  /* every created thread */
extern OSThread *D_80098010;  /* running thread */
extern OSThread *D_80098014;  /* faulted thread */
extern OSTimer *D_80098160;   /* timer list head */
extern s32 D_8009804C;        /* set once the console is shutting down */
extern u32 D_80098050;        /* interrupts enabled for every thread */
extern s32 D_80098100;        /* the pre-NMI event was already seen */
extern __OSHwInterrupt D_80097FD0[];
extern OSDevMgr D_80098060;           /* Pi device manager */
extern OSPiHandle *D_8009807C;        /* every linked Pi handle */
extern OSPiHandle *D_80098080[];      /* handle whose timings the Pi registers hold, per domain */
extern s32 D_80098090;                /* the Pi access queue exists */
extern u32 D_80000308;                /* base address of the cartridge ROM */
extern __OSEventState D_8009E8E0[];
extern OSTime D_8009E980;     /* time at the last base count */
extern u32 D_8009E988;        /* count register at that time */
extern u32 D_8009E990;        /* count register at the last timer interrupt */

OSIntMask __osDisableInt(void);
void __osRestoreInt(OSIntMask mask);
void __osSetCompare(u32 value);
u32 osGetCount(void);

/* Thread scheduler (hand-written assembly and the queue helpers around it). */
void func_800892E4(OSThread **queue);                 /* put the running thread in the queue and switch */
void func_800893E4(OSThread **queue, OSThread *t);    /* insert by priority */
OSThread *func_8008942C(OSThread **queue);            /* remove and return the first thread */
void func_80089444(void);                             /* run the first thread of the run queue */
void func_800895D0(OSThread **queue, OSThread *t);    /* remove from the queue */

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri);
void osStartThread(OSThread *t);
void osStopThread(OSThread *t);
void osSetThreadPri(OSThread *t, OSPri pri);
OSPri osGetThreadPri(OSThread *t);
OSId osGetThreadId(OSThread *t);
void osYieldThread(void);

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count);
s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flags);
s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flags);
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flags);

#define OS_IM_RCP 0x00000401

u32 __osProbeTLB(void *vaddr);
u32 osVirtualToPhysical(void *vaddr);
void __osPiCreateAccessQueue(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
s32 osEPiLinkHandle(OSPiHandle *handle);
s32 osEPiStartDma(OSPiHandle *handle, OSIoMesg *mb, s32 direction);
s32 osEPiReadIo(OSPiHandle *handle, u32 devAddr, u32 *data);
s32 osEPiWriteIo(OSPiHandle *handle, u32 devAddr, u32 data);
s32 __osEPiRawReadIo(OSPiHandle *handle, u32 devAddr, u32 *data);
s32 __osEPiRawWriteIo(OSPiHandle *handle, u32 devAddr, u32 data);
s32 __osEPiRawStartDma(OSPiHandle *handle, s32 direction, u32 cartAddr, void *dramAddr, u32 size);
s32 __osPiRawStartDma(s32 direction, u32 cartAddr, void *dramAddr, u32 size);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQueue, OSMesg *cmdBuf, s32 cmdMsgCount);
void __osDevMgrMain(void *args);
OSMesgQueue *osPiGetCmdQueue(void);

s32 osStopTimer(OSTimer *t);
s32 osSetTimer(OSTimer *t, OSTime value, OSTime interval, OSMesgQueue *mq, OSMesg msg);
OSTime __osInsertTimer(OSTimer *t);
void __osSetTimerIntr(OSTime time);
void __osTimerInterrupt(void);
void __osTimerServicesInit(void);
OSTime osGetTime(void);
void osSetTime(OSTime time);

OSThread *__osGetCurrFaultedThread(void);
OSThread *__osGetActiveQueue(void);
void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg);
void __osSetGlobalIntMask(OSHWIntr mask);
void __osResetGlobalIntMask(OSHWIntr mask);
void __osGetHWIntrRoutine(OSHWIntr interrupt, s32 (**handler)(void), void **stackEnd);

#endif
