#include "types.h"

typedef struct {
    u8 pad0[6];
    u8 unk6;
    u8 unk7;
} Fn80138B84Ent;

extern Fn80138B84Ent *func_80100304(s32);
extern void SkinMatrix_GetClear(s32 *);
extern void SkinMatrix_MtxFMtxFMult(s32, s32, s32 *);
extern void SkinMatrix_MtxFCopy(s32 *, s32);

s32 func_80138B84(s32 arg0, s32 *arg1, s32 arg2, u8 arg3, u8 arg4) {
    s32 r;
    Fn80138B84Ent *sp70;
    s32 sp6C;
    struct { s32 a; s32 b[17]; } sp24; // matching: one block pins the stack layout

    sp70 = func_80100304(arg1[arg4]);
    if (arg3 == 0xFF) {
        SkinMatrix_GetClear(&sp6C);
    } else {
        sp6C = (arg3 << 6) + arg2;
    }
    sp24.a = (arg4 << 6) + arg2;
    SkinMatrix_MtxFMtxFMult(sp6C, sp24.a, sp24.b);
    SkinMatrix_MtxFCopy(sp24.b, sp24.a);
    if (sp70->unk6 != 0xFF) {
        r = func_80138B84(arg0, arg1, arg2, arg4, sp70->unk6);
        if (r != 0) {
            return r;
        }
    }
    if (sp70->unk7 != 0xFF) {
        r = func_80138B84(arg0, arg1, arg2, arg3, sp70->unk7);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
