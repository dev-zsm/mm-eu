// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 align;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 align1;
} ContRequestFormat;

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} PifRam;

extern u8 D_8009D2E0;
extern u8 D_8009D2E1;
extern PifRam D_8009E9A0;

void __osPfsRequestData(u8 cmd) {
    u8 *ptr = (u8 *)D_8009E9A0.ramarray;
    ContRequestFormat req;
    s32 i;

    D_8009D2E0 = cmd;
    D_8009E9A0.pifstatus = 1;
    req.align = 0xFF;
    req.txsize = 1;
    req.rxsize = 3;
    req.cmd = cmd;
    req.typeh = 0xFF;
    req.typel = 0xFF;
    req.status = 0xFF;
    req.align1 = 0xFF;
    for (i = 0; i < D_8009D2E1; i++) {
        *(ContRequestFormat *)ptr = req;
        ptr += sizeof(ContRequestFormat);
    }
    *ptr = 0xFE;
}
