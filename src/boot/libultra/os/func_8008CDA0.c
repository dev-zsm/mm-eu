// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp) {
    u16 sp58[4];
    u32 pad;
    struct {
        u16 inverse;
        u16 sum;
    } check;
    u16 *page;
    s32 i;
    s32 j;
    s32 ret;

    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    sp58[0] = 1;
    sp58[1] = 3;
    sp58[2] = 4;
    sp58[3] = 6;
    i = 1;
    page = &sp58[1];
    for (;;) {
        ret = __osContRamRead(pfs->queue, pfs->channel, *page, (u8 *)temp);
        if (ret != 0) {
            return ret;
        }
        __osIdCheckSum((u16 *)temp, &check.sum, &check.inverse);
        if (temp->checksum == check.sum && temp->invertedChecksum == check.inverse) {
            break;
        }
        i += 1;
        page += 1;
        if (i == 4) {
            break;
        }
    }
    if (i == 4) {
        return PFS_ERR_ID_FATAL;
    }
    for (j = 0; j != 4; j++) {
        if (j != i) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, sp58[j], (u8 *)temp, 1);
            if (ret != 0) {
                return ret;
            }
        }
    }
    return 0;
}
