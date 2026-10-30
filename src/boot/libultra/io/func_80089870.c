// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 __osMotorAccess(OSPfs *pfs, s32 flag) {
    s32 pad[2]; // stack padding to match frame size
    u8 *ptr = D_8009D180 + (pfs->channel << 6);
    s32 i;
    s32 ret;

    if (!(pfs->status & PFS_MOTOR_INITIALIZED)) {
        return PFS_ERR_INVALID;
    }
    __osSiGetAccess();
    ((OSPifRam *)(D_8009D180 + (pfs->channel << 6)))->pifstatus = 1;
    ptr = (u8 *)((u32)ptr + pfs->channel);
    for (i = 0; i < 32; i++) {
        ((__OSContRamFormat *)ptr)->data[i] = flag;
    }
    D_8009D2E0 = CONT_CMD_END;
    __osSiRawStartDma(OS_WRITE, D_8009D180 + (pfs->channel << 6));
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    __osSiRawStartDma(OS_READ, D_8009D180 + (pfs->channel << 6));
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    if ((ret = ((__OSContRamFormat *)ptr)->rxsize & 0xC0) == 0) {
        if (flag == 0) {
            if (((__OSContRamFormat *)ptr)->datacrc != 0) {
                ret = PFS_ERR_CONTRFAIL;
            }
        } else {
            if (((__OSContRamFormat *)ptr)->datacrc != 0xEB) {
                ret = PFS_ERR_CONTRFAIL;
            }
        }
    }
    __osSiRelAccess();
    return ret;
}
