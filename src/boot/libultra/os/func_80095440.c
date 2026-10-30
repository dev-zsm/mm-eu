// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

void osCreateViManager(OSPri pri) {
    OSIntMask savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (D_800983A0.active == 0) {
        __osTimerServicesInit();
        D_800983BC = 0;
        osCreateMesgQueue(&D_8009FC10, D_8009FC28, 5);
        D_8009FC40.hdr.type = OS_MESG_TYPE_VRETRACE;
        D_8009FC40.hdr.pri = OS_MESG_PRI_NORMAL;
        D_8009FC40.hdr.retQueue = NULL;
        D_8009FC58.hdr.type = OS_MESG_TYPE_COUNTER;
        D_8009FC58.hdr.pri = OS_MESG_PRI_NORMAL;
        D_8009FC58.hdr.retQueue = NULL;
        osSetEventMesg(OS_EVENT_VI, &D_8009FC10, &D_8009FC40);
        osSetEventMesg(OS_EVENT_COUNTER, &D_8009FC10, &D_8009FC58);
        oldPri = -1;
        myPri = osGetThreadPri(NULL);
        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(NULL, pri);
        }
        savedMask = __osDisableInt();
        D_800983A0.active = 1;
        D_800983A0.thread = &D_8009EA60;
        D_800983A0.cmdQueue = &D_8009FC10;
        D_800983A0.evtQueue = &D_8009FC10;
        D_800983A0.acsQueue = NULL;
        D_800983A0.dma = NULL;
        D_800983A0.edma = NULL;
        osCreateThread(&D_8009EA60, 0, viMgrMain, &D_800983A0, D_8009EC10 + sizeof(D_8009EC10), pri);
        __osViInit();
        osStartThread(&D_8009EA60);
        __osRestoreInt(savedMask);
        if (oldPri != -1) {
            osSetThreadPri(NULL, oldPri);
        }
    }
}
