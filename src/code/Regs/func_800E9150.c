// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_debug.h"

void Regs_Init(void) {
    s32 i;

    gRegEditor = malloc(sizeof(RegEditor));
    if (1) {}
    gRegEditor->regPage = 0;
    gRegEditor->regGroup = 0;
    gRegEditor->regCur = 0;
    gRegEditor->inputRepeatTimer = 0;
    gRegEditor->dPadInputPrev = 0;

    for (i = 0; i < ARRAY_COUNT(gRegEditor->data); i++) {
        gRegEditor->data[i] = 0;
    }
}
