// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osPfsGetStatus(OSMesgQueue *queue, s32 channel) {
    s32 ret;
    OSMesg dummy;
    OSContStatus data;
    s32 status;

    D_800980F4 = 0xFA; /* invalidate the cached inode page */
    __osPfsRequestOneChannel(channel, CONT_CMD_REQUEST_STATUS);
    __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &D_8009E9A0);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    __osPfsGetOneChannelData(channel, &data);
    status = data.status;
    if ((status & 1) && (status & 2)) {
        return PFS_ERR_NEW_PACK;
    }
    if ((data.errno != 0) || (!(status & 1))) {
        return PFS_ERR_NOPACK;
    }
    if (status & 4) {
        return PFS_ERR_CONTRFAIL;
    }
    return ret;
}
