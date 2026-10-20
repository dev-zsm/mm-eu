// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Entry;

Entry *func_80080944(u32 addr);

s32 func_800809A0(u32 addr) {
    Entry *e = func_80080944(addr);
    if (e != NULL) {
        if (e->unkC == 0) {
            return e->unk8 + addr - e->unk0;
        }
        if (addr == e->unk0) {
            return e->unk8;
        }
        return -1;
    }
    return -1;
}
