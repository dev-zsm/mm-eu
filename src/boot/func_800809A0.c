// FLAGS: -O2 -g0 -mips2
#include "types.h"

// Translates addr through the range table (see func_80080944). Linear ranges map
// base + (addr - start); flagged ranges only map their exact start address.
// Returns -1 if addr is not mapped.
typedef struct {
    u32 start;
    u32 end;
    u32 base;
    u32 flags;
} MapEntry;

MapEntry *func_80080944(u32 addr);

s32 func_800809A0(u32 addr) {
    MapEntry *e = func_80080944(addr);
    if (e != NULL) {
        if (e->flags == 0) {
            return e->base + addr - e->start;
        }
        if (addr == e->start) {
            return e->base;
        }
        return -1;
    }
    return -1;
}
