#ifndef OS_INTERNAL_H
#define OS_INTERNAL_H

#include "ultra64.h"
#include "os_vi.h"
#include "stackcheck.h"
#include "irqmgr.h"
#include "fault.h"
#include "printf.h"

/* Kernel helpers of libultra/os that no public header declares, and the boot sequence of src/boot/unknown. */

#define OS_EVENT_COUNTER 3
#define OS_EVENT_VI 7

#define OS_MESG_TYPE_VRETRACE 13
#define OS_MESG_TYPE_COUNTER 14

#define OS_TV_PAL 0
#define OS_TV_NTSC 1
#define OS_TV_MPAL 2

/* Pak command with a 5-bit address checksum: 32 data bytes follow, then the data checksum (0x27 bytes). */
typedef struct {
    /* 0x00 */ u8 dummy;
    /* 0x01 */ u8 txsize;
    /* 0x02 */ u8 rxsize;
    /* 0x03 */ u8 cmd;
    /* 0x04 */ u8 addrh;
    /* 0x05 */ u8 addrl;
    /* 0x06 */ u8 data[32];
    /* 0x26 */ u8 datacrc;
} __OSContRamReadFormat;

/* Thread queues. */
void func_80089610(OSThread *t); /* remove a thread (NULL: the running one) from its queue and from the list of all threads */
void __osSetHWIntrRoutine(OSHWIntr interrupt, s32 (*handler)(void), void *stackEnd);

u32 osGetMemSize(void);

/* Video interface manager. */
extern OSDevMgr D_800983A0;
extern OSThread D_8009EA60;
extern u8 D_8009EC10[0x1000];  /* thread stack, ends at D_8009FC10 */
extern OSMesgQueue D_8009FC10;
extern OSMesg D_8009FC28[5];
extern OSIoMesg D_8009FC40;    /* retrace message */
extern OSIoMesg D_8009FC58;    /* counter message */

void osCreateViManager(OSPri pri);
void viMgrMain(void *arg);

/* Boot sequence (src/boot/unknown). */
extern u32 D_80000318;      /* size of the RAM, as osMemSize */
extern u8 D_80000500[];     /* frame buffer shown while booting, 320x240 pixels of 16 bits */
extern u8 D_80025D00[];
extern u8 D_80080060[];
extern u8 D_802006E0[];
extern u8 D_801DB830[];
extern u8 D_800A5FE0[];
extern u8 D_C8A000[];       /* ROM address, start of the segment copied by func_80080260 */
extern u8 D_DBF850[];       /* ROM address, end of that segment */
extern s8 D_80096CC0;
extern volatile u8 D_80096CC4;
extern u8 D_80096CC8;
extern u32 D_80096CCC;      /* argument of osViSetSpecialFeatures */
extern f32 D_80096CD0;      /* x scale */
extern f32 D_80096CD4;      /* y scale */
extern OSPiHandle *D_80096CE0;  /* cartridge handle used for the ROM copies */
extern u32 D_80096CF0;      /* size of one ROM copy chunk, 0: a single transfer */
extern OSViMode D_80098320;
extern f32 D_80098440;
extern char D_80098430[];
extern char D_80098438[];
extern OSViMode D_8009B610; /* mode set by func_8008019C and func_80080600 */
extern s8 D_8009B660;
extern IrqMgr D_8009B390;
extern u8 D_8009A2C0[0x500];    /* stack of the main thread, ends at D_8009A7C0 */
extern StackEntry D_8009A7C0;
extern OSThread D_8009A7E0;
extern u8 D_8009A990[0x900];    /* stack of the boot thread, ends at D_8009B290 */
extern StackEntry D_8009B290;
extern OSMesg D_8009B2B0[0x32]; /* command buffer of the Pi manager */
extern OSMesgQueue D_8009B378;  /* command queue of the Pi manager */

void func_80080150(void *start, void *end); /* clear [start, end) */
void func_80080180(u32 *dst, u32 size, u32 value);
void func_8008019C(void);
void func_800801FC(void);
void func_80080260(void);
void func_80080310(void *arg);
void func_800803B0(void);
void func_80080538(void *arg);
void func_80080600(s32 useDefaultMode);
void func_80080778(void);
s32 func_80080924(OSPiHandle *handle, OSIoMesg *mb, s32 direction);

void func_80081870(void);
void func_80081878(void);

/* Fault screen helpers (src/boot/unknown). */
extern u32 D_8009C200;
extern u32 D_8009C204;
extern FaultClient D_8009C208;      /* client that shows the RCP status page */
extern const char D_80098510[];
extern const char D_80098520[];
extern const char D_80098534[];
extern const char D_80098744[];
extern const char D_800998A0[];
extern const char D_800998AC[];

void func_80081880(void);           /* draws the RCP status page */
void func_800818EC(void);
void func_80081920(void);
void func_80081944(void);
void func_80081970(const char *fmt, ...);
void func_800819A8(const char *fmt, ...);
void func_800849C8(void);

/* Helpers whose names are unknown. */
void func_80085074(u32 rangeStart, u32 rangeEnd, u32 start, u32 end, void *buf); /* defined in src/boot/wip */
void *func_80085140(u32 rangeStart, u32 rangeEnd, u32 start, u32 end);
void func_800851A0(void *ptr);
void func_800851C0(void);
void func_800851C8(void *ptr);
s32 func_800851D4(u16 *ptr, u16 value);
s32 func_800879F4(char *buf, const char *fmt, va_list args); /* likely vsprintf */
s64 func_80088BD8(s64 x, s64 y);    /* signed modulo, the result takes the sign of y */
s64 func_80088C74(s64 x, s64 shift);
s32 func_80096A50(const u8 *s1, const u8 *s2); /* strcmp */
char *func_80096A90(char *dst, const char *src); /* strcpy */

void func_800816D4(IrqMgr *irqMgr);
void func_800817A4(IrqMgr *irqMgr, void *stack, OSPri pri, u8 retraceCount);

/* Fields of two Pi handles (type, latency, page size, release duration, pulse width); the handle symbols themselves
 * are not named in the ROM. Domain 1 is the cartridge ROM. */
extern s8 D_8009D504;
extern s8 D_8009D505;
extern s8 D_8009D506;
extern s8 D_8009D507;
extern s8 D_8009D508;
extern s8 D_8009D57C;
extern s8 D_8009D57D;
extern s8 D_8009D57E;
extern s8 D_8009D57F;
extern s8 D_8009D580;

void func_8008A800(void);   /* save the Pi timing registers of both domains in the two handles */

#endif
