#include "types.h"

typedef struct {
    u8 pad0[0xBC];
    s32 unkBC;
    u8 padC0[0xE38];
    u8 flags[1];
} Data;

typedef struct {
    u8 pad0[0x120B5];
    u8 count;
    u8 list[1];
} Buf;

extern s32 D_801C2A38;
extern u16 D_801C7FE8[];
extern Data D_801E6EF0;

void func_801520F8(u8 *a0, u8 a1) {
    u16 v;
    u8 lo;
    Buf *p;

    if (D_801C2A38 & D_801E6EF0.unkBC) {
        v = D_801C7FE8[a1];
        p = (Buf *)(a0 + 0x4908);
        lo = v;
        if (!(lo & D_801E6EF0.flags[v >> 8])) {
            p->list[p->count] = a1;
            p->count = p->count + 1;
        }
    } else if (a1 >= 0x14) {
        v = D_801C7FE8[a1];
        p = (Buf *)(a0 + 0x4908);
        lo = v;
        if (!(lo & D_801E6EF0.flags[v >> 8])) {
            p->list[p->count] = a1;
            p->count = p->count + 1;
        }
    }
}
