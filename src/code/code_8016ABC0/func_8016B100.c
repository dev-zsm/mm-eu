#include "types.h"

typedef struct {
    u8 pad0[0x3CB0];
    s32 unk3CB0;
    u8 pad3CB4[0x50];
    u16 unk3D04;
} D_801E6EF0_Type;

typedef struct {
    u8 pad0[0x18875];
    u8 unk18875;
    u8 pad18876[4];
    u16 unk1887A;
    u8 pad1887C[3];
    u8 unk1887F;
} Ctx_8016B100;

extern D_801E6EF0_Type D_801E6EF0;
extern void func_8016B054(Ctx_8016B100 *ctx);

void func_8016B100(Ctx_8016B100 *ctx) {
    ctx->unk1887A = D_801E6EF0.unk3D04;
    D_801E6EF0.unk3CB0 = -1;
    func_8016B054(ctx);
    ctx->unk18875 = 0x14;
    ctx->unk1887F = 2;
}
