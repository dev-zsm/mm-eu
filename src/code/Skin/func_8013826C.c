#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx_8013826C;

typedef struct {
    /* 0x000 */ u8 pad0[0x2B0];
    /* 0x2B0 */ Gfx_8013826C *unk2B0;
} GfxCtx_8013826C;

typedef struct {
    /* 0x0 */ u8 pad0[8];
    /* 0x8 */ u32 unk8;
    /* 0xC */ s32 unkC;
} Limb_8013826C;

extern void *func_80100304(s32);
extern void func_80137EE4(GfxCtx_8013826C *, s32 **, s32, s32);

void Skin_DrawAnimatedLimb(GfxCtx_8013826C *arg0, s32 **arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 pad[4]; // unused, only to match the ROM frame size
    Limb_8013826C *limb;
    Gfx_8013826C *dl;

    limb = func_80100304(((Limb_8013826C *)func_80100304(((s32 *)func_80100304(**arg1))[arg2]))->unkC);
    if (!(arg4 & 1)) {
        func_80137EE4(arg0, arg1, arg2, arg3);
    }
    dl = arg0->unk2B0++;
    dl->w0 = 0xDE000000;
    dl->w1 = limb->unk8;
}
