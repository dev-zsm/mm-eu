// FLAGS: -O2 -g3 -mips2
#include "types.h"

void SkinMatrix_MtxFMtxFMult(void *, void *, void *);
void SkinMatrix_SetScale(void *, s32, s32, s32);
void SkinMatrix_SetRotateRPY(void *, s16, s16, s16);
void SkinMatrix_SetTranslate(void *, s32, s32, s32);

void SkinMatrix_SetScaleRotateRPYTranslate(void *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9) {
    u8 sp58[0x40];
    u8 sp18[0x40];

    SkinMatrix_SetTranslate(arg0, arg7, arg8, arg9);
    SkinMatrix_SetRotateRPY(sp58, arg4, arg5, arg6);
    SkinMatrix_MtxFMtxFMult(arg0, sp58, sp18);
    SkinMatrix_SetScale(sp58, arg1, arg2, arg3);
    SkinMatrix_MtxFMtxFMult(sp18, sp58, arg0);
}
