#include "types.h"

typedef struct {
    u8 pad0[0x220];
    s16 unk220;
} Sub;

typedef struct {
    u8 pad0[0x1F2C];
    u8 unk1F2C;
} Ctx;

extern s16 D_801C03E8;
extern s16 D_801C03EC;
extern u8 D_801D3DD4[];
extern void Audio_PlaySfx(s32);
extern void Audio_PlaySfx_AtPosWithReverb(void *, s32, s32);

void func_80115868(Ctx *ctx, u16 a1) {
    Sub *s = (Sub *)((u8 *)ctx + 0x169E8);

    if (a1 == 0x2A || a1 == 0x2B) {
        if (s->unk220 == 0 && ctx->unk1F2C == 0) {
            if (a1 == 0x2B) {
                Audio_PlaySfx(0x6843);
            }
            if (a1 == 0x2A) {
                Audio_PlaySfx_AtPosWithReverb(D_801D3DD4, 0x685F, 0x20);
            }
            s->unk220 = 1;
            D_801C03E8 = 0;
            D_801C03EC = 0xA;
            return;
        }
    }
    if (a1 == 0x2C) {
        if (s->unk220 != 0) {
            s->unk220 = 0;
        }
    }
}
