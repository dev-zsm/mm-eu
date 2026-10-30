// FLAGS: -O2 -g0
#include "ultra64.h"

extern OSThread D_8009D5F0;      /* Pi manager thread */
extern OSMesgQueue D_8009E7A0;   /* Pi event queue; the stack of the thread ends where it begins */
extern OSMesg D_8009E7B8[1];
extern OSMesgQueue D_8009E7C8;   /* Pi access queue */

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQueue, OSMesg *cmdBuf, s32 cmdMsgCount) {
    OSIntMask saveMask;
    OSPri oldPri;
    OSPri myPri;

    if (D_80098060.active == 0) {
        osCreateMesgQueue(cmdQueue, cmdBuf, cmdMsgCount);
        osCreateMesgQueue(&D_8009E7A0, D_8009E7B8, 1);
        if (D_80098090 == 0) {
            __osPiCreateAccessQueue();
        }
        osSetEventMesg(8, &D_8009E7A0, (OSMesg)0x22222222);
        oldPri = -1;
        myPri = osGetThreadPri(NULL);
        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(NULL, pri);
        }
        saveMask = __osDisableInt();
        D_80098060.active = 1;
        D_80098060.cmdQueue = cmdQueue;
        D_80098060.thread = &D_8009D5F0;
        D_80098060.evtQueue = &D_8009E7A0;
        D_80098060.acsQueue = &D_8009E7C8;
        D_80098060.dma = __osPiRawStartDma;
        D_80098060.edma = __osEPiRawStartDma;
        osCreateThread(&D_8009D5F0, 0, __osDevMgrMain, &D_80098060, &D_8009E7A0, pri);
        osStartThread(&D_8009D5F0);
        __osRestoreInt(saveMask);
        if (oldPri != -1) {
            osSetThreadPri(NULL, oldPri);
        }
    }
}
