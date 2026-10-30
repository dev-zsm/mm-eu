// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 __osContRamWrite(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer, s32 force) {
    s32 ret = 0;
    s32 i;
    u8 *ptr;
    u8 crc;
    s32 retry = 2;

    if (force != 1 && address < 7 && address != 0) {
        return 0;
    }
    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != CONT_CMD_WRITE_MEMPACK || channel != D_800981A0) {
            D_8009D2E0 = CONT_CMD_WRITE_MEMPACK;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ((__OSContRamFormat *)ptr)->dummy = 0xFF;
            ((__OSContRamFormat *)ptr)->txsize = 0x23;
            ((__OSContRamFormat *)ptr)->rxsize = 1;
            ((__OSContRamFormat *)ptr)->cmd = CONT_CMD_WRITE_MEMPACK;
            ((__OSContRamFormat *)ptr)->datacrc = 0xFF;
            ((__OSContRamFormat *)ptr)->end = CONT_CMD_END;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ((__OSContRamFormat *)ptr)->addrh = address >> 3;
        ((__OSContRamFormat *)ptr)->addrl = __osContAddressCrc(address) | (address << 5);
        bcopy(buffer, ((__OSContRamFormat *)ptr)->data, PFS_BLOCKSIZE);
        __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
        crc = __osContDataCrc(buffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osSiRawStartDma(OS_READ, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ret = (((__OSContRamFormat *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (crc != ((__OSContRamFormat *)ptr)->datacrc) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret != 0) {
                    break;
                }
                ret = PFS_ERR_CONTRFAIL;
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && !(retry-- < 0));
    __osSiRelAccess();
    return ret;
}
