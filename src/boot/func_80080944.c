// FLAGS: -O2 -g0 -mips2
#include "types.h"

// One range of the translation table D_8009FC80 (see DmaMgr_TranslateVromToRom).
// flags == 0: linear mapping. Nonzero: only the exact start address matches (inferred).
typedef struct {
    u32 start;
    u32 end;
    u32 base;
    u32 flags;
} MapEntry;

extern MapEntry D_8009FC80[];

// Finds the range containing addr in D_8009FC80, which is terminated by an entry with end == 0.
// Returns NULL if no range contains addr.
MapEntry *DmaMgr_FindDmaEntry(u32 addr) {
    MapEntry *p;
    MapEntry *first = D_8009FC80;
    if (first->end != 0) {
        p = first;
        while (1) {
            if (addr >= p->start && addr < p->end) return p;
            p++;
            if (p->end == 0) break;
        }
    }
    return NULL;
}
