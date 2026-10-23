// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2E0;
extern u8 D_8009E9A0[];

typedef struct {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
} Req6;

void __osPfsRequestOneChannel(s32 channel, u8 poll) {
    u8 *ptr;
    Req6 fmt;
    s32 i;

    D_8009D2E0 = 0xFE;
    *(s32 *)(D_8009E9A0 + 0x3C) = 1;
    ptr = D_8009E9A0;
    fmt.txsize = 1;
    fmt.rxsize = 3;
    fmt.cmd = poll & 0xFF;
    fmt.typeh = 0xFF;
    fmt.typel = 0xFF;
    fmt.status = 0xFF;
    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }
    *(Req6 *)ptr = fmt;
    ptr += sizeof(Req6);
    ptr[0] = 0xFE;
}
