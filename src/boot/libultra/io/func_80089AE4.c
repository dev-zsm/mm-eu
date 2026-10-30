// FLAGS: -O2 -g0
#include "os_pfs.h"

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, s32 channel) {
    s32 ret;
    u8 temp[32];

    pfs->queue = mq;
    pfs->channel = channel;
    pfs->activeBank = 0xFF;
    pfs->status = 0;

    ret = __osPfsSelectBank(pfs, 0xFE);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = __osPfsSelectBank(pfs, 0x80);
    }
    if (ret != 0) {
        return ret;
    }

    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = PFS_ERR_CONTRFAIL;
    }
    if (ret != 0) {
        return ret;
    }
    if (temp[0x1F] == 0xFE) {
        return PFS_ERR_DEVICE;
    }

    ret = __osPfsSelectBank(pfs, 0x80);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = PFS_ERR_CONTRFAIL;
    }
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = PFS_ERR_CONTRFAIL;
    }
    if (ret != 0) {
        return ret;
    }
    if (temp[0x1F] != 0x80) {
        return PFS_ERR_DEVICE;
    }
    if (!(pfs->status & PFS_MOTOR_INITIALIZED)) {
        __osMakeMotorData(channel, D_8009D180 + (channel << 6));
    }
    pfs->status = PFS_MOTOR_INITIALIZED;
    return 0;
}
