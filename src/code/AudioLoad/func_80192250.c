// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x20];
    /* 0x30 */ u8 mq[0x18];
    /* 0x48 */ u8 msg[4];
    /* 0x4C */ u8 unk4C[1];
} DmaSlowCopyCtx;

extern u8 D_801D7BD8[];

extern void Audio_InvalDCache(s32 arg0);
extern void func_8008F3E0(void* mq, void* msg, s32 count);
extern void func_8019155C(void* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, void* a6, s32 a7, void* a8);
void AudioLoad_DmaSlowCopy(DmaSlowCopyCtx* ctx, s32 arg1) {
    Audio_InvalDCache(ctx->unkC);
    func_8008F3E0(ctx->mq, ctx->msg, 1);
    func_8019155C(ctx->unk4C, 0, 0, ctx->unk8, ctx->unkC, arg1, ctx->mq, ctx->unk0, D_801D7BD8);
}
