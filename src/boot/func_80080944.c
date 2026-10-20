// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Entry;

extern Entry D_8009FC80[];

Entry *func_80080944(u32 addr) {
    Entry *p;
    Entry *base = D_8009FC80;
    if (base->unk4 != 0) {
        p = base;
        while (1) {
            if (addr >= p->unk0 && addr < p->unk4) return p;
            p++;
            if (p->unk4 == 0) break;
        }
    }
    return NULL;
}
