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
} ReadFmt;

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

s32 __osContRamRead(void *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret = 0;
    s32 i;
    u8 *ptr;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != 2 || channel != D_800981A0) {
            D_8009D2E0 = 2;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ((ReadFmt *)ptr)->dummy = 0xFF;
            ((ReadFmt *)ptr)->txsize = 3;
            ((ReadFmt *)ptr)->rxsize = 0x21;
            ((ReadFmt *)ptr)->cmd = 2;
            ((ReadFmt *)ptr)->datacrc = 0xFF;
            ((ReadFmt *)ptr)->end = 0xFE;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ((ReadFmt *)ptr)->addrh = address >> 3;
        ((ReadFmt *)ptr)->addrl = __osContAddressCrc(address) | (address << 5);
        __osSiRawStartDma(1, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (((ReadFmt *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (__osContDataCrc(ptr + 6) != ((ReadFmt *)ptr)->datacrc) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret != 0) {
                    break;
                }
                ret = 4;
            } else {
                bcopy(ptr + 6, buffer, 32);
            }
        } else {
            ret = 1;
        }
    } while (ret == 4 && !(retry-- < 0));
    __osSiRelAccess();
    return ret;
}
