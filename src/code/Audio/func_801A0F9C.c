#include "types.h"

typedef struct {
    f32 value;
    f32 target;
    f32 step;
    s32 remaining;
} FreqLerp;

void Audio_StepFreqLerp(FreqLerp *lerp) {
    if (lerp->remaining != 0) {
        lerp->remaining--;
        if (lerp->remaining != 0) {
            lerp->value += lerp->step;
        } else {
            lerp->value = lerp->target;
        }
    }
}
