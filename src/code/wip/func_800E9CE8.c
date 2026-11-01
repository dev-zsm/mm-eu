#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad0[0x1C0]; Gfx *unk1C0; u8 pad1C4[0x2A8 - 0x1C4]; u8 unk2A8[8]; Gfx *unk2B0; } Ctx;
extern s32 func_80173A30(void *);
extern void GfxPrint_Init(void *);
extern void GfxPrint_Destroy(void *);
extern void GfxPrint_Open(void *, Gfx *);
extern Gfx *GfxPrint_Close(void *);
extern Gfx *Gfx_Open(Gfx *);
extern void Gfx_Close(Gfx *, Gfx *);
extern void Debug_DrawScreenText(void *);
extern void func_800E9C04(void *);
extern s32 D_801BBBC0;
extern s16 D_801BBC2C;
void func_800E9CE8(Ctx *ctx) {
    u8 sp30[0x30];
    Gfx *opa;
    Gfx *g;
    if (func_80173A30(ctx->unk2A8) >= 0x2800) {
        GfxPrint_Init(sp30);
        opa = ctx->unk2B0;
        g = Gfx_Open(opa);
        ctx->unk1C0->w0 = 0xDE000000; ctx->unk1C0->w1 = (u32)g; ctx->unk1C0++;
        GfxPrint_Open(sp30, g);
        if (D_801BBBC0 & 2) {
            func_800E9C04(sp30);
        }
        D_801BBC2C = 0;
        if (D_801BBBC0 & 1) {
            Debug_DrawScreenText(sp30);
        }
        g = GfxPrint_Close(sp30);
        g->w0 = 0xDF000000; g->w1 = 0; g++;
        Gfx_Close(opa, g);
        ctx->unk2B0 = g;
        GfxPrint_Destroy(sp30);
    }
}
