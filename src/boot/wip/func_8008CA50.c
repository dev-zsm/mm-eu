// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u8 pad0[4];
    void *unk4;
    void *unk8;
    u8 pad0C[0x65 - 0x0C];
    u8 unk65;
} Ctx;

typedef struct {
    u8 pad0[8];
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u16 unk18;
    u8 pad1A[2];
    u8 unk1B;
} Src;

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u16 unk18;
    s8 unk1A;
    u8 unk1B;
    u16 unk1C;
    u16 unk1E;
} Dst;

s32 osGetCount(void);
s32 __osPfsSelectBank(Ctx *ctx, s32 x);
s32 __osContRamRead(void *a0, void *a1, s32 a2, void *a3);
s32 __osContRamWrite(void *a0, void *a1, s32 a2, void *a3, s32 a4);
s32 __osIdCheckSum(void *a0, void *a1, void *a2);

s32 __osRepairPackId(Ctx *ctx, Src *src, Dst *dst) {
    u8 sp5C[0x20];
    u8 sp7C[0x20];
    u16 sp48[4];
    s32 ret;
    s32 s3;
    s32 i;
    s32 v0;
    u16 *s0;

    dst->unk0 = -1;
    dst->unk4 = osGetCount();
    dst->unk8 = src->unk8;
    dst->unkC = src->unkC;
    dst->unk10 = src->unk10;
    dst->unk14 = src->unk14;

    if (ctx->unk65 != 0) {
        ret = __osPfsSelectBank(ctx, 0);
        if (ret != 0) {
            return ret;
        }
    }

    s3 = 0;
    for (;;) {
        ret = __osPfsSelectBank(ctx, s3 & 0xFF);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(ctx->unk4, ctx->unk8, 0, sp7C);
        if (ret != 0) {
            return ret;
        }
        sp7C[0] = s3 | 0x80;
        for (i = 1; i < 0x20; i++) {
            sp7C[i] = ~sp7C[i];
        }
        ret = __osContRamWrite(ctx->unk4, ctx->unk8, 0, sp7C, 0);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(ctx->unk4, ctx->unk8, 0, sp5C);
        if (ret != 0) {
            return ret;
        }

        for (i = 0; i < 0x20; i++) {
            if (sp5C[i] != sp7C[i]) {
                break;
            }
        }
        if (i != 0x20) {
            break;
        }
        if (s3 <= 0) {
            s3++;
        } else {
            ret = __osPfsSelectBank(ctx, 0);
            if (ret != 0) {
                return ret;
            }
            ret = __osContRamRead(ctx->unk4, ctx->unk8, 0, sp7C);
            if (ret != 0) {
                return ret;
            }
            if (sp7C[0] != 0x80) {
                break;
            }
            s3++;
        }
        if (s3 >= 0x3E) {
            break;
        }
    }

    if (ctx->unk65 != 0) {
        ret = __osPfsSelectBank(ctx, 0);
        if (ret != 0) {
            return ret;
        }
    }

    if (s3 > 0) {
        v0 = 1;
    } else {
        v0 = 0;
    }
    dst->unk1A = s3;
    dst->unk18 = (src->unk18 & 0xFFFE) | v0;
    dst->unk1B = src->unk1B;
    __osIdCheckSum(dst, &dst->unk1C, &dst->unk1E);

    sp48[0] = 1;
    sp48[1] = 3;
    sp48[2] = 4;
    sp48[3] = 6;
    s0 = sp48;
    do {
        ret = __osContRamWrite(ctx->unk4, ctx->unk8, *s0, dst, 1);
        if (ret != 0) {
            return ret;
        }
        s0++;
    } while (s0 < sp48 + 4);

    ret = __osContRamRead(ctx->unk4, ctx->unk8, 1, sp7C);
    if (ret != 0) {
        return ret;
    }

    {
        u8 *a = sp7C;
        u8 *b = (u8 *)dst;
        do {
            if (a[0] != b[0] || a[1] != b[1] || a[2] != b[2] || a[3] != b[3]) {
                return 0xB;
            }
            a += 4;
            b += 4;
        } while (a != sp7C + 0x20);
    }
    return 0;
}
