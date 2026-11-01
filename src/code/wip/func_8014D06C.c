#include "types.h"

typedef struct {
    u8 pad0[0x11F28]; u16 arr[1];
} Msg;
typedef struct { u8 pad0[0x1209C - 0x11F28]; f32 f; } Msg2;
typedef struct { u8 pad0[0x4908]; u8 msg[1]; } Ctx;

extern void func_800F4D00(Ctx *, u16, u8 *);

void func_8014D06C(Ctx *ctx, u16 a1, u8 **a2, f32 *a3, s16 a4) {
    u8 *dl = *a2;
    f32 f = *a3;

    func_800F4D00(ctx, a1, dl);
    ((Msg *)ctx->msg)->arr[a4] = a1;
    *a2 = dl + 0x80;
    *a3 = f + 16.0f * ((Msg2 *)((u8 *)ctx->msg + 0x11F28))->f;
}
