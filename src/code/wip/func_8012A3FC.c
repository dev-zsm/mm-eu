#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx_;
typedef struct {
    u8 pad0[0x2B0];
    Gfx_ *unk2B0;
} GC;
typedef struct {
    GC *gfxCtx;
    u8 pad4[0xA0];
    s32 unkA4;
} Draw;

extern void func_8012D3BC(GC *, s32, s32, s32, s32, s32);
extern void func_8012C920(GC *);

void PreNMI_Draw(Draw *this) {
    GC *gfx = this->gfxCtx;
    Gfx_ *p;

    func_8012D3BC(gfx, 1, 1, 0, 0, 0);
    func_8012C920(gfx);
    p = gfx->unk2B0++;
    p->w1 = -1;
    p->w0 = 0xF7000000;
    p = gfx->unk2B0++;
    p->w0 = (((this->unkA4 + 0x64) & 0x3FF) << 2) | 0xF64FC000;
    p->w1 = ((this->unkA4 + 0x64) & 0x3FF) << 2;
}
