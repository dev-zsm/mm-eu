// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} OSContStatus;

extern u8 D_8009D2E1;
extern u8 D_8009E9A0[];

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osPfsRequestData(s32 cmd);
s32 __osSiRawStartDma(s32 dir, void *a1);
void osRecvMesg(s32 mq, void *msg, s32 flag);
void __osPfsGetInitData(u8 *pattern, OSContStatus *data);

s32 osPfsIsPlug(s32 queue, u8 *pattern) {
    s32 ret = 0;
    void *dummy;
    u8 bitpattern;
    OSContStatus data[4];
    s32 channel;
    u8 bits = 0;
    s32 crcErrorCount = 3;

    __osSiGetAccess();
    do {
        __osPfsRequestData(0);
        ret = __osSiRawStartDma(1, D_8009E9A0);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, D_8009E9A0);
        osRecvMesg(queue, &dummy, 1);
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
