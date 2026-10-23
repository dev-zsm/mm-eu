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
    u8 data[36];
    u8 datacrc;
    u8 end;
} VoiceReadFmt;

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} PifRam;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(void *mq, void *msg, s32 flag);
void __osSiRawStartDma(s32 dir, void *buf);
s32 __osVoiceGetStatus(void *mq, s32 channel, u8 *status);
s32 __osContAddressCrc(u16 addr);
u8 __osVoiceContDataCrc(u8 *data, s32 size);
void bcopy(void *src, void *dst, s32 n);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern PifRam D_8009E9A0;

s32 __osVoiceContRead36(void *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret = 0;
    u8 status;
    s32 i;
    u8 *ptr;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != 9 || channel != D_800981A0) {
            D_8009D2E0 = 9;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ((VoiceReadFmt *)ptr)->dummy = 0xFF;
            ((VoiceReadFmt *)ptr)->txsize = 3;
            ((VoiceReadFmt *)ptr)->rxsize = 0x25;
            ((VoiceReadFmt *)ptr)->cmd = 9;
            ((VoiceReadFmt *)ptr)->datacrc = 0xFF;
            ((VoiceReadFmt *)ptr)->end = 0xFE;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ((VoiceReadFmt *)ptr)->addrh = address >> 3;
        ((VoiceReadFmt *)ptr)->addrl = __osContAddressCrc(address) | (address << 5);
        __osSiRawStartDma(1, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (((VoiceReadFmt *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (__osVoiceContDataCrc(ptr + 6, 36) != ((VoiceReadFmt *)ptr)->datacrc) {
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = 4;
            } else {
                bcopy(ptr + 6, buffer, 36);
            }
        } else {
            ret = 1;
        }
    } while (ret == 4 && !(retry-- < 0));
    __osSiRelAccess();
    return ret;
}
