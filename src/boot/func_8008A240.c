// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    s8 rawStickX;
    s8 rawStickY;
} ReadFormat;

typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} PifRam;

extern PifRam D_8009D2A0;
extern u8 D_8009D2E1;

void __osPackReadData(void) {
    u8 *ptr;
    ReadFormat readformat;
    s32 i;

    ptr = (u8 *)D_8009D2A0.ramarray;
    for (i = 0; i < 15; i++) {
        D_8009D2A0.ramarray[i] = 0;
    }
    D_8009D2A0.pifstatus = 1;
    readformat.dummy = 0xFF;
    readformat.txsize = 1;
    readformat.rxsize = 4;
    readformat.cmd = 1;
    readformat.button = 0xFFFF;
    readformat.rawStickX = -1;
    readformat.rawStickY = -1;
    for (i = 0; i < D_8009D2E1; i++) {
        *(ReadFormat *)ptr = readformat;
        ptr += sizeof(ReadFormat);
    }
    *ptr = 0xFE;
}
