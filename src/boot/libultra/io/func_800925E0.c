// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern) {
    s32 ret = 0;
    OSMesg dummy;
    u8 bitpattern;
    OSContStatus data[MAXCONTROLLERS];
    s32 channel;
    u8 bits = 0;
    s32 crcErrorCount = 3;

    __osSiGetAccess();
    do {
        __osPfsRequestData(CONT_CMD_REQUEST_STATUS);
        ret = __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
        osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
        ret = __osSiRawStartDma(OS_READ, &D_8009E9A0);
        osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
        __osPfsGetInitData(&bitpattern, data);
        for (channel = 0; channel < D_8009D2E1; channel++) {
            if ((data[channel].status & 4) == 0) {
                crcErrorCount--;
                break;
            }
        }
        if (channel == D_8009D2E1) {
            crcErrorCount = 0;
        }
    } while (crcErrorCount > 0);
    for (channel = 0; channel < D_8009D2E1; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1) != 0) {
            bits |= 1 << channel;
        }
    }
    __osSiRelAccess();
    *pattern = bits;
    return ret;
}
