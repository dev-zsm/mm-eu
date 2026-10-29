#include "types.h"

typedef struct {
    u8 pad0[0xA];
    u16 v;
    u8 pad1[0x20 - 0xC];
} E;

typedef struct {
    u8 pad0[0x1C];
    s16 i;
    u8 pad1[0x116 - 0x1E];
    u16 v;
    u8 pad2[0x13C - 0x118];
    void *p;
    u8 pad3[0x1A0 - 0x140];
    s16 z;
} T;

extern u8 D_808640E8[];
extern E D_80864170[];

void func_80000E84(s32 a, T *b) {
    E *e = &D_80864170[b->i];
    b->v = e->v;
    b->z = 0;
    b->p = D_808640E8;
}
