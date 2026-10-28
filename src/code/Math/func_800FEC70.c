#include "types.h"

extern f32 D_801C9E18;
s32 Math_ScaledStepToS(s16 *pValue, s16 target, s16 step) {
    short new_var;
    f32 scale;
    if (step != 0) {
        scale = D_801C9E18;
        if (((s16) ((*pValue) - target)) > 0) {
            step = -step;
        }
        new_var = (s32) (step * scale);
        *pValue += new_var;
        if (((s32) (((u32) ((s16) ((*pValue) - target))) * ((u32) step))) >= 0) {
            *pValue = target;
            return 1;
        }
    } else
        if (target == (*pValue)) {
        return 1;
    }
    return 0;
}
