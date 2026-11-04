// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fireobj_ctx.h"

void FireObj_StepSize(FireObj* fire) {
    if (fire->state == FIRE_STATE_GROWING) {
        if (Math_StepToF(&fire->dynamicSize, 1.0f, fire->dynamicSizeStep)) {
            FireObj_SetState(fire, fire->dynamicSizeStep, FIRE_STATE_FULLY_LIT);
        }
    } else if ((fire->state == FIRE_STATE_SHRINKING) && Math_StepToF(&fire->dynamicSize, 0.0f, fire->dynamicSizeStep)) {
        FireObj_SetState(fire, fire->dynamicSizeStep, FIRE_STATE_NOT_LIT);
    }
    if (fire->sizeGrowsCos2 == 1) {
        if ((fire->state == FIRE_STATE_GROWING) || (fire->state == FIRE_STATE_SHRINKING)) {
            fire->xScale = (1.0f - Math_CosS(SQ(fire->dynamicSize) * 0x4000)) * fire->size;
            fire->yScale = fire->dynamicSize * fire->size;
        } else {
            fire->yScale = fire->dynamicSize * fire->size;
            fire->xScale = fire->dynamicSize * fire->size;
        }
        return;
    } else {
        fire->yScale = fire->dynamicSize * fire->size;
    }
    fire->xScale = fire->dynamicSize * fire->size;
}
