// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    void *unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} Func800807E0Ctx;

extern u32 D_80096CF0;
extern void *D_80096CE0;
extern s32 osEPiStartDma(void *a, void *b, s32 c);
extern void osRecvMesg(void *a, s32 b, s32 c);
extern void osCreateMesgQueue(void *a, void *b, s32 c);
extern void osInvalDCache(u32 a, u32 b);

s32 func_800807E0(u32 dst, u32 src, u32 rem) {
    u32 chunk;
    s32 ret;
    s32 var44;
    u8 bufA[24];
    Func800807E0Ctx ctx;

    chunk = D_80096CF0;
    osInvalDCache(src, rem);
    osCreateMesgQueue(bufA, &var44, 1);
    ret = 0;
    if (chunk != 0 && chunk < rem) {
        do {
            ctx.unk2 = 0;
            ctx.unk4 = bufA;
            ctx.unk8 = src;
            ctx.unkC = dst;
            ctx.unk10 = chunk;
            ret = osEPiStartDma(*(void **)&D_80096CE0, &ctx, 0);
            if (ret != 0) {
                break;
            }
            osRecvMesg(bufA, 0, 1);
            rem -= chunk;
            dst += chunk;
            src += chunk;
        } while (chunk < rem);
    }
    if (ret == 0) {
        ctx.unk2 = 0;
        ctx.unk4 = bufA;
        ctx.unk8 = src;
        ctx.unkC = dst;
        ctx.unk10 = rem;
        ret = osEPiStartDma(*(void **)&D_80096CE0, &ctx, 0);
        if (ret == 0) {
            osRecvMesg(bufA, 0, 1);
            osInvalDCache(src, rem);
        }
    }
    return ret;
}
