#include "types.h"

typedef struct {
    u8 pad0[0x170A8];
    s16 unk170A8;
    s16 unk170AA;
    u8 pad170AC[0x2E];
    s16 unk170DA;
    s16 unk170DC;
} Ctx;

void Environment_LerpFog(Ctx *ctx, s16 a, s16 b, f32 f) {
    ctx->unk170A8 = (a - ctx->unk170DA) * f;
    ctx->unk170AA = (b - ctx->unk170DC) * f;
}
