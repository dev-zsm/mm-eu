// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 b[8];
} Entry;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Dst;

extern u8 D_8009D2E1;
extern u8 D_8009E9A0[];

void func_80092820(u8 *arg0, Dst *arg1) {
    s32 i;
    u8 bits;
    Entry sp;
    Entry *src;
    u8 field;

    bits = 0;
    src = (Entry *)D_8009E9A0;
    i = 0;
    if (D_8009D2E1 > 0) {
        do {
            sp = *src;
            field = (sp.b[2] & 0xC0) >> 4;
            arg1->unk3 = field;
            if (field == 0) {
                arg1->unk0 = (sp.b[5] << 8) | sp.b[4];
                bits |= 1 << i;
                arg1->unk2 = sp.b[6];
            }
            arg1++;
            src++;
            i++;
        } while (i < D_8009D2E1);
    }
    *arg0 = bits;
}
