// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18];
    u32 count;
    u8 *list;
} ColList;

void Collider_ResetATBase(s32);
void func_800E1424(s32, u8 *);

s32 Collider_ResetTrisAT(s32 arg0, ColList *arg1) {
    u8 *p;
    ColList *l;

    l = arg1;
    Collider_ResetATBase(arg0);
    p = l->list;
    if (p < l->list + l->count * 0x5C) {
        do {
            func_800E1424(arg0, p);
            p += 0x5C;
        } while (p < l->list + l->count * 0x5C);
    }
    return 1;
}
