#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx_;
typedef struct {
    u8 pad0[0x2C0];
    Gfx_ *p;
} GC;
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 pad[0x18];
} Entry;

extern Entry D_801BBCA0[];
void func_8012C78C(GC *);
u32 Matrix_Finalize(GC *);

void GetItem_DrawXlu01(GC **arg0, s16 arg1) {
    Gfx_ *a; s32 pad; GC *gfx;
    Gfx_ *b;
    Entry *e;

    gfx = *arg0;
    func_8012C78C(gfx);
    a = gfx->p++;
    a->w0 = 0xDA380003;
    a->w1 = Matrix_Finalize(*arg0);
    b = gfx->p++;
    b->w0 = 0xDE000000;
    e = &D_801BBCA0[arg1];
    b->w1 = e->unk4;
    b = gfx->p++;
    b->w0 = 0xDE000000;
    b->w1 = e->unk8;
}
