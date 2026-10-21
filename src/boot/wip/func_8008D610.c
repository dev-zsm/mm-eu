// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 flags;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x44];
    s32 count;
    u8 pad54[8];
    s32 base;
} Ctx;

typedef struct {
    s32 w0;
    u16 h4;
    u8 pad56[6];
    u8 b5C[4];
    u8 b60[0x10];
} Buf;

s32 func_8008D0B0(Ctx *ctx);
s32 func_80090DE0(s32 a0, s32 a1, u16 a2, Buf *a3);
s32 func_8008B560(s32 a0, s32 a1);

s32 func_8008D610(Ctx *ctx, u16 key, s32 fe, u8 *a3, u8 *a4, s32 *out) {
    s32 i;
    s32 ret;
    s32 mismatch;
    Buf buf;

    if (!(ctx->flags & 1)) {
        return 5;
    }
    ret = func_8008D0B0(ctx);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < ctx->count; i++) {
        ret = func_80090DE0(ctx->unk4, ctx->unk8, (u16)(ctx->base + i), &buf);
        if (ret != 0) {
            return ret;
        }
        ret = func_8008B560(ctx->unk4, ctx->unk8);
        if (ret == 0) {
            if (buf.h4 == key && buf.w0 == fe) {
                mismatch = 0;
                if (a3 != NULL) {
                    s32 j;
                    for (j = 0; j < 0x10; j++) {
                        if (buf.b60[j] != a3[j]) {
                            mismatch = 1;
                            break;
                        }
                    }
                }
                if (a4 != NULL && mismatch == 0) {
                    s32 j;
                    for (j = 0; j < 4; j++) {
                        if (buf.b5C[j] != a4[j]) {
                            mismatch = 1;
                            break;
                        }
                    }
                }
                if (mismatch == 0) {
                    *out = i;
                    return ret;
                }
            }
        } else {
            return ret;
        }
    }
    *out = -1;
    return 5;
}
