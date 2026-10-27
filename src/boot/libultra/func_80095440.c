// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 active;
    void *thread;
    void *cmdQueue;
    void *evtQueue;
    void *acsQueue;
    void *dma;
    void *edma;
} DevMgr;

typedef struct {
    u16 type;
    u8 pad2;
    u32 pad4;
} Msg;

extern DevMgr D_800983A0;
extern s32 D_800983BC;
extern u8 D_8009EA60[];
extern u8 D_8009EC10[0x1000]; /* viMgr thread stack, ends at D_8009FC10 */
extern u8 D_8009FC10[];
extern u8 D_8009FC28[];
extern Msg D_8009FC40;
extern Msg D_8009FC58;

void __osTimerServicesInit(void);
void osCreateMesgQueue(void *a, void *b, s32 c);
void osSetEventMesg(s32 a, void *b, void *c);
s32 osGetThreadPri(void *a);
void osSetThreadPri(void *a, s32 b);
s32 __osDisableInt(void);
void osCreateThread(void *a, s32 b, void *c, void *d, void *e, s32 f);
void __osViInit(void);
void osStartThread(void *a);
void __osRestoreInt(s32 a);
void viMgrMain(void *a);

void osCreateViManager(s32 pri) {
    s32 savedMask;
    s32 oldPri;
    s32 myPri;

    if (D_800983A0.active == 0) {
        __osTimerServicesInit();
        D_800983BC = 0;
        osCreateMesgQueue(D_8009FC10, D_8009FC28, 5);
        D_8009FC40.type = 13;
        D_8009FC40.pad2 = 0;
        D_8009FC40.pad4 = 0;
        D_8009FC58.type = 14;
        D_8009FC58.pad2 = 0;
        D_8009FC58.pad4 = 0;
        osSetEventMesg(7, D_8009FC10, &D_8009FC40);
        osSetEventMesg(3, D_8009FC10, &D_8009FC58);
        oldPri = -1;
        myPri = osGetThreadPri(0);
        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(0, pri);
        }
        savedMask = __osDisableInt();
        D_800983A0.active = 1;
        D_800983A0.thread = D_8009EA60;
        D_800983A0.cmdQueue = D_8009FC10;
        D_800983A0.evtQueue = D_8009FC10;
        D_800983A0.acsQueue = 0;
        D_800983A0.dma = 0;
        D_800983A0.edma = 0;
        osCreateThread(D_8009EA60, 0, viMgrMain, &D_800983A0, D_8009EC10 + sizeof(D_8009EC10), pri);
        __osViInit();
        osStartThread(D_8009EA60);
        __osRestoreInt(savedMask);
        if (oldPri != -1) {
            osSetThreadPri(0, oldPri);
        }
    }
}
