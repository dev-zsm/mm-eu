// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 b[8]; } Entry;
typedef struct { u32 w0; u32 w1; } Ent4;
typedef struct { u16 unk0; u8 unk2; u8 unk3; } Dst;
extern u8 D_8009D2E1;
extern u8 D_8009E9A0[];
void func_80092820(u8 *arg0, Dst *arg1) {
    s32 i;
    u8 bits;
    union { Ent4 w; Entry e; } sp;
    Entry *src;
    bits = 0;
    src = (Entry *)D_8009E9A0;
    for (i = 0; i < D_8009D2E1; i++) {
        sp.w = *(Ent4 __unaligned *)src;
        arg1->unk3 = (sp.e.b[2] & 0xC0) >> 4;
        if (arg1->unk3 == 0) {
            arg1->unk0 = (sp.e.b[5] << 8) | sp.e.b[4];
            bits |= 1 << i;
            arg1->unk2 = sp.e.b[6];
        }
        arg1++;
        src++;
    }
    *arg0 = bits;
}
