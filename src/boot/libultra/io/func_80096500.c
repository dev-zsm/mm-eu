// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 osVoiceControlGain(OSVoiceHandle *hd, s32 analog, s32 digital) {
    s32 ret;
    u8 data;

    if (analog == 0) {
        data = 0x18;
    } else {
        data = 0x98;
    }
    ret = __osVoiceSetADConverter(hd->mq, hd->channel, data);
    if (ret != 0) {
        return ret;
    }
    if (digital < 8 && digital >= 0) {
        data = D_80098410[digital] + 2;
    } else {
        return PFS_ERR_INVALID;
    }
    ret = __osVoiceSetADConverter(hd->mq, hd->channel, data);
    if (ret != 0) {
        return ret;
    }
    return ret;
}
