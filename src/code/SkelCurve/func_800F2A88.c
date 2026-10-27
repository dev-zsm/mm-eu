#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    void *limbs;
} SkelCurve;

void SkelCurve_DrawLimb(s32 arg0, s32 arg1, SkelCurve *skelCurve, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void SkelCurve_Draw(s32 arg0, s32 arg1, SkelCurve *skelCurve, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (skelCurve->limbs != NULL) {
        SkelCurve_DrawLimb(arg1, 0, skelCurve, arg3, arg4, arg5, arg6);
    }
}
