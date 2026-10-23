// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 addrh;
    u8 addrl;
    u8 data[32];
    u8 datacrc;
    u8 end;
} WriteFmt;

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} PifRam;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(void *mq, void *msg, s32 flag);
void __osSiRawStartDma(s32 dir, void *buf);
s32 __osPfsGetStatus(void *mq, s32 channel);
s32 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8 *data);
void bcopy(void *src, void *dst, s32 n);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern PifRam D_8009E9A0;

s32 __osContRamWrite(void *mq, s32 channel, u16 address, u8 *buffer, s32 force) {
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
        if (D_8009D2E0 != 3 || channel != D_800981A0) {
            D_8009D2E0 = 3;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ((WriteFmt *)ptr)->dummy = 0xFF;
            ((WriteFmt *)ptr)->txsize = 0x23;
            ((WriteFmt *)ptr)->rxsize = 1;
            ((WriteFmt *)ptr)->cmd = 3;
            ((WriteFmt *)ptr)->datacrc = 0xFF;
            ((WriteFmt *)ptr)->end = 0xFE;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ((WriteFmt *)ptr)->addrh = address >> 3;
        ((WriteFmt *)ptr)->addrl = __osContAddressCrc(address) | (address << 5);
        bcopy(buffer, ptr + 6, 32);
        __osSiRawStartDma(1, &D_8009E9A0);
        crc = __osContDataCrc(buffer);
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (((WriteFmt *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (crc != ((WriteFmt *)ptr)->datacrc) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret != 0) {
                    break;
                }
                ret = 4;
            }
        } else {
            ret = 1;
        }
    } while (ret == 4 && !(retry-- < 0));
    __osSiRelAccess();
    return ret;
}
