// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} PifRam;

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
} ReqFmt;

extern PifRam D_8009D2A0;
extern u8 D_8009D2E1;

void __osPackRequestData(u8 cmd) {
    u8 *ptr;
    ReqFmt req;
    s32 i;

    for (i = 0; i < 15; i++) {
        D_8009D2A0.ramarray[i] = 0;
    }
    D_8009D2A0.pifstatus = 1;
    ptr = (u8 *)D_8009D2A0.ramarray;
    req.dummy = 0xFF;
    req.txsize = 1;
    req.rxsize = 3;
    req.cmd = cmd;
    req.typeh = 0xFF;
    req.typel = 0xFF;
    req.status = 0xFF;
    req.dummy1 = 0xFF;
    for (i = 0; i < D_8009D2E1; i++) {
        *(ReqFmt *)ptr = req;
        ptr += sizeof(ReqFmt);
    }
    *ptr = 0xFE;
}
