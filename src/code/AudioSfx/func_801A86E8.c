#include "types.h"

typedef struct {
    f32 value;
    f32 target;
    f32 step;
    u16 unkC;
    u16 padE;
} BankLerp;

extern BankLerp D_801F74D0[];

void AudioSfx_StepBankLerp(u8 index) {
    BankLerp *lerp = &D_801F74D0[index];

    if (lerp->unkC != 0) {
        lerp->unkC--;
        if (lerp->unkC != 0) {
            lerp->value -= lerp->step;
        } else {
            lerp->value = lerp->target;
        }
    }
}
