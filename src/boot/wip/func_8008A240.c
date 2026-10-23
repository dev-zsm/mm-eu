// FLAGS: -O2 -g0
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

extern u32 D_8009D2A0[16];
extern u8 D_8009D2E1;

void __osPackReadData(void) {
    u8 *ptr;
    ReadFormat readformat;
    s32 i;

    for (i = 0; i < 15; i++) {
        D_8009D2A0[i] = 0;
    }
    D_8009D2A0[15] = 1;
    ptr = (u8 *)D_8009D2A0;
    readformat.dummy = 0xFF;
    readformat.txsize = 1;
    readformat.rxsize = 4;
    readformat.cmd = 1;
    readformat.button = -1;
    readformat.rawStickX = -1;
    readformat.rawStickY = -1;
    for (i = 0; i < D_8009D2E1; i++) {
        *(ReadFormat *)ptr = readformat;
        ptr += sizeof(ReadFormat);
    }
    *ptr = 0xFE;
}
