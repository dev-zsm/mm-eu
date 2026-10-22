// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u8 unk0; u8 unk1; u8 unk2; u8 unk3; u8 unk4; u8 unk5; u8 unk6; u8 unk7;
} Entry;

typedef union {
    Entry e;
    s32 w[2];
} Tpl;

extern u32 D_8009D2A0[16];
extern u8 D_8009D2E1;

void __osPackReadData(void) {
    u8 n; Entry *dst; u32 *p; s32 i; Tpl tpl;
    p = D_8009D2A0;
    do {
        p++;
        p[-1] = 0;
    } while (p < &D_8009D2A0[15]);
    D_8009D2A0[15] = 1;

    n = D_8009D2E1;
    tpl.e.unk0 = 0xFF;
    tpl.e.unk1 = 1;
    tpl.e.unk2 = 4;
    tpl.e.unk3 = 1;
    *(u16 *)&tpl.e.unk4 = 0xFFFF;
    tpl.e.unk6 = 0xFF;
    tpl.e.unk7 = 0xFF;

    dst = (Entry *) D_8009D2A0;
    i = 0;
    if ((s32) n > 0) {
        do {
            i++;
            *dst = tpl.e;
            dst++;
        } while (i < (s32) n);
    }
    ((u8 *) dst)[0] = 0xFE;
}
