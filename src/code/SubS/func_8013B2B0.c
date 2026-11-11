#include "types.h"
#include "generated/code_funcs.h"

void SubS_TimePathing_FillKnots(f32 *arg0, s32 arg1, s32 arg2) {
    f32 f;
    s32 i;

    f = 0.0f;
    for (i = 0; i < arg2; i++) {
        if (i >= arg1 && i < arg2 - arg1 + 1) {
            f += 1.0f;
        }
        arg0[i] = f;
    }
}
