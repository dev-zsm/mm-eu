#include "types.h"
typedef struct {
    u8 pad0[0x1CA5];
    u8 unk1CA5;
    u8 pad1[0x18875 - 0x1CA6];
    u8 unk18875;
    u8 pad2[4];
    u16 unk1887A;
    u8 pad3[3];
    u8 unk1887F;
} Ctx;
typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 pad1[0xA];
    s32 unk18;
    s32 unk1C;
    u8 pad2[0x3F4A - 0x20];
    s16 unk3F4A;
} G;
extern G D_801E6EF0;
void AudioSeq_QueueSeqCmd(s32, void *);
void func_8011CA74(Ctx *ctx) {
    if (ctx->unk1CA5 & 2) {
        AudioSeq_QueueSeqCmd(0xE0000100, ctx);
    }
    D_801E6EF0.unk18 = 4;
    D_801E6EF0.unk1C = 4;
    D_801E6EF0.unkC = 0x400A;
    ctx->unk1887A = 0x54C0;
    D_801E6EF0.unk3F4A = 0;
    ctx->unk18875 = 0x14;
    ctx->unk1887F = 3;
}
