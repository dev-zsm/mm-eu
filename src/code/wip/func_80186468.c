#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx_80186468;

typedef struct {
    /* 0x000 */ u8 pad0[0x2B0];
    /* 0x2B0 */ Gfx_80186468 *unk2B0;
    /* 0x2B4 */ u8 pad2B4[0xC];
    /* 0x2C0 */ Gfx_80186468 *unk2C0;
} GfxCtx_80186468;

extern void func_80186140(GfxCtx_80186468 **, s32, s32 *, s32, s32, s32, s32 *);

void func_80186468(GfxCtx_80186468 **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 sp3C;
    GfxCtx_80186468 *gfxCtx;
    Gfx_80186468 *dl;

    if (arg2 != 0) {
        gfxCtx = *arg0;
        dl = gfxCtx->unk2B0++;
        dl->w0 = 0xDB060034;
        dl->w1 = arg2;
        dl = gfxCtx->unk2C0++;
        dl->w0 = 0xDB060034;
        dl->w1 = arg2;
        sp3C = 0;
        func_80186140(arg0, arg1, &sp3C, arg3, arg4, arg5, &arg2);
    }
}
